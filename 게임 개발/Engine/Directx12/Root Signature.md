# Root Signature

![image-20231208164343655](../../../image/image-20231208164343655.png)

## 루트 시그니처?

Root Signature(루트 서명)는 Direct3D 12에서 그래픽 파이프라인의 루트에 위치하는 객체로, GPU에서 쉐이더 및 리소스에 대한 접근 규칙을 정의한다. 루트 서명은 쉐이더에 필요한 루트 디스크립터(Root Descriptor)를 결정하고, 그래픽 파이프라인 상에서 렌더링에 사용되는 상수 버퍼, 텍스처, 언바인드 리소스 등에 대한 바인딩을 설정한다.

## 루트 서명이 포함하는 항목들

1. **루트 서명 인자(Root Signature Parameters)**: 각각의 루트 서명 인자는 쉐이더에서 사용되는 루트 디스크립터를 정의한다. 루트 디스크립터는 상수 버퍼, 텍스처, 언바인드된 리소스 등과 같은 GPU 자원에 대한 정보를 포함한다.
2. **루트 서명 인자 슬롯(Root Signature Parameter Slots)**: 각 슬롯은 하나의 루트 서명 인자에 대응하며, 쉐이더에서 사용되는 루트 디스크립터를 바인딩하는 데 사용된다.
3. **루트 디스크립터 테이블(Root Descriptor Tables)**: 루트 디스크립터 테이블은 동적인 자원 배열을 위한 것으로, 여러 개의 루트 디스크립터를 담고 있다. 예를 들어, 여러 텍스처를 한 번에 바인딩하거나, 다양한 상수 버퍼를 동적으로 업데이트하고자 할 때 사용된다.
4. **루트 상수(Root Constants)**: 쉐이더에 전달할 상수 값을 포함하는 영역으로, 각각의 상수는 32비트 워드로 제한된다. 루트 상수를 사용하여 쉐이더에 상수 데이터를 전달할 수 있다.

## 루트 서명이 생성되는 과정

1. **루트 서명 설명 작성**: 루트 서명의 구조와 각 슬롯에 대한 정보를 작성한다.
2. **루트 서명 생성**: 작성한 루트 서명 설명을 사용하여 루트 서명을 생성한다.

루트 서명은 렌더링 파이프라인 초기화 단계에서 사용되며, GPU에게 쉐이더 및 자원에 대한 액세스 규칙을 알려준다. 또한, 동적으로 업데이트되는 자원이나 렌더링 과정에서 변경되는 자원에 대한 유연성을 제공한다.

아래는 간단한 C++ 코드를 사용하여 루트 서명을 생성하는 예시이다.

```c++
cppCopy code// 루트 서명 설명 작성
CD3DX12_ROOT_PARAMETER rootParameters[1];
CD3DX12_DESCRIPTOR_RANGE descriptorRange(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1, 0);
rootParameters[0].InitAsDescriptorTable(1, &descriptorRange);

CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
rootSignatureDesc.Init(1, rootParameters, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

// 루트 서명 생성
ID3DBlob* signature;
ID3DBlob* error;
D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, &error);

ID3D12RootSignature* rootSignature;
device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&rootSignature));

// 생성한 루트 서명 및 루트 서명 설명의 블롭을 해제
SafeRelease(signature);
SafeRelease(error);
```

위 코드에서 `D3D12_ROOT_PARAMETER` 및 `D3D12_ROOT_SIGNATURE_DESC`는 Direct3D 12에서 사용되는 구조체이다. 이를 통해 루트 서명을 작성하고 생성할 수 있다.