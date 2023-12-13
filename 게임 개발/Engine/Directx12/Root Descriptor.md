# Root Descriptor

## 루트 디스크립터?


Root Descriptor(루트 디스크립터)는 Direct3D 12 그래픽 파이프라인에서 사용되는 루트 서명(Root Signature)의 일부로, 쉐이더에서 접근할 수 있는 GPU 자원에 대한 정보를 제공한다. 루트 디스크립터는 주로 상수 버퍼, 텍스처, 언바인드된 리소스 등과 같은 GPU 리소스에 대한 바인딩 정보를 담고 있다.

## 루트 디스크립터의 특징

1. **Descriptor Heap을 사용**: 루트 디스크립터는 주로 Descriptor Heap에 저장되며, Descriptor Heap은 GPU 자원에 대한 디스크립터들을 관리하는 메모리 영역이다. Descriptor Heap에는 **CBV(상수 버퍼 뷰), SRV(텍스처 및 버퍼 뷰), UAV(언바인드된 리소스 뷰)** 등의 디스크립터가 저장된다.
2. **Descriptor Index 사용**: 루트 디스크립터는 Descriptor Heap 내에서 자원에 대한 디스크립터의 인덱스를 참조한다. 이 인덱스는 루트 서명에서 정의한 루트 디스크립터 테이블의 슬롯에 위치한다.
3. **동적 업데이트 가능**: 일부 루트 디스크립터는 런타임 중에 동적으로 업데이트될 수 있다. 예를 들어, 프레임마다 다르게 바인딩되어야 하는 상수 버퍼나 텍스처와 같은 자원들을 업데이트할 수 있다.

루트 디스크립터는 렌더링 파이프라인에서 GPU에게 쉐이더에서 사용할 자원에 대한 위치를 알려준다. 이를 통해 렌더링할 때마다 변경되는 자원들에 대한 유연성을 제공하며, 쉐이더가 이러한 자원들을 접근할 때 정확한 메모리 주소나 디스크립터의 인덱스를 사용할 수 있도록 한다.

## 루트 디스크립터를 생성하고 사용하는 코드

```c++
cppCopy code// Descriptor Heap 생성
D3D12_DESCRIPTOR_HEAP_DESC heapDesc = {};
// ... (heapDesc 설정)

ID3D12DescriptorHeap* descriptorHeap;
device->CreateDescriptorHeap(&heapDesc, IID_PPV_ARGS(&descriptorHeap));

// 루트 디스크립터 테이블 생성
D3D12_ROOT_DESCRIPTOR_TABLE rootDescriptorTable;
// ... (루트 디스크립터 테이블 설정)

// 루트 서명 생성 (루트 디스크립터 테이블 사용)
CD3DX12_ROOT_PARAMETER rootParameters[1];
rootParameters[0].InitAsDescriptorTable(1, &rootDescriptorTable);

CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
rootSignatureDesc.Init(1, rootParameters, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

ID3DBlob* signature;
D3D12SerializeRootSignature(&rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &signature, nullptr);

ID3D12RootSignature* rootSignature;
device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&rootSignature));

// 생성한 루트 서명 및 루트 서명 설명의 블롭을 해제
SafeRelease(signature);
```

위 코드에서 `rootDescriptorTable`은 루트 디스크립터 테이블을 설정하는데 사용되며, 이를 루트 서명에 추가하여 루트 서명을 생성한다.

## CBV, SRV, UAV에 대한 깊은 설명
CBV(상수 버퍼 뷰), SRV(텍스처 및 버퍼 뷰), UAV(언바운드된 리소스 뷰)는 Direct3D 12에서 GPU 자원에 대한 서술자(Descriptor)를 나타내는 세 가지 유형이다. 이들은 주로 루트 서명(Root Signature)에서 사용되며, 쉐이더에서 접근하는 GPU 자원에 대한 정보를 정의한다.

1. **CBV(상수 버퍼 뷰 - Constant Buffer View)**:

   - **용도**: 주로 상수 버퍼(Constant Buffer)에 대한 서술자로 사용.
   - **설명**: CBV는 GPU에서 사용되는 상수 버퍼의 뷰를 나타낸다. 상수 버퍼는 쉐이더에서 공유 데이터를 사용하는 데에 주로 활용되며, 이를 통해 동적으로 변경되는 상수 값을 전달할 수 있다.

2. **SRV(텍스처 및 버퍼 뷰 - Shader Resource View)**:

   - **용도**: 텍스처나 버퍼에 대한 읽기 전용 서술자로 사용.
   - **설명**: SRV는 텍스처, 버퍼 및 구조화된 버퍼(Structured Buffer)에 대한 뷰를 나타낸다. 이를 통해 쉐이더에서 텍스처를 읽거나 버퍼의 데이터를 읽을 수 있다.

3. **UAV(언바운드된 리소스 뷰 - Unordered Access View)**:

   - **용도**: 주로 쓰기 작업을 수행하는 리소스에 대한 서술자로 사용.

   - **설명**: UAV는 쉐이더에서 리소스에 대한 쓰기 작업을 수행할 때 사용된다. 텍스처나 버퍼에 대한 쓰기 작업을 수행할 때 이 서술자를 통해 해당 리소스에 접근한다. 주로 GPGPU(General-Purpose computing on Graphics Processing Units) 계산에서 활용된다. 

     ***GPGPU** : 일반적인 그래픽 처리 장치(Graphics Processing Unit)를 사용하여 범용 계산을 수행하는 기술이나 접근 방식을 나타낸다. 일반적으로 그래픽 처리 장치는 그래픽 작업을 처리하기 위해 설계되었지만, GPGPU를 통해 이러한 장치를 고성능 병렬 계산을 수행하는 데에 활용할 수 있다.

     GPGPU의 핵심 아이디어는 그래픽 카드가 수천 개의 코어로 병렬 처리를 수행할 수 있다는 점을 활용하여 범용 계산에 적용하는 것이다. 그래픽 처리 장치는 대량의 데이터를 동시에 처리하는 데 탁월한 성능을 발휘할 수 있기 때문에, 일부 병렬 계산 작업에 대해 CPU보다 훨씬 높은 성능을 제공할 수 있다.

이들 서술자는 Direct3D 12에서 Descriptor Heap에 저장되며, 루트 서명에서 이러한 Descriptor Heap의 특정 위치를 가리키도록 구성된다. Descriptor Heap은 GPU 자원에 대한 디스크립터들을 관리하는 메모리 영역으로, CBV, SRV, UAV 등을 저장하고 쉐이더에서 접근 가능하게 한다.

## 다음은 간단한 C++ 코드를 사용하여 CBV, SRV, UAV를 생성하고 사용하는 예시

```c++
cppCopy code// 상수 버퍼 생성
ID3D12Resource* constantBuffer;
// ... (상수 버퍼 생성 및 데이터 업로드)

// CBV 서술자 생성
D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc = {};
cbvDesc.BufferLocation = constantBuffer->GetGPUVirtualAddress();
cbvDesc.SizeInBytes = // ... (상수 버퍼의 크기);
device->CreateConstantBufferView(&cbvDesc, descriptorHeap->GetCPUDescriptorHandleForHeapStart());

// 텍스처 생성
ID3D12Resource* texture;
// ... (텍스처 생성 및 데이터 업로드)

// SRV 서술자 생성
D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
srvDesc.Format = // ... (텍스처 포맷);
srvDesc.ViewDimension = // ... (텍스처 차원);
srvDesc.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
srvDesc.Texture2D.MostDetailedMip = 0;
srvDesc.Texture2D.MipLevels = -1;
device->CreateShaderResourceView(texture, &srvDesc, descriptorHeap->GetCPUDescriptorHandleForHeapStart());

// 언바인드된 리소스 생성
ID3D12Resource* unorderedAccessResource;
// ... (리소스 생성 및 데이터 초기화)

// UAV 서술자 생성
D3D12_UNORDERED_ACCESS_VIEW_DESC uavDesc = {};
uavDesc.Format = // ... (리소스 포맷);
uavDesc.View
```