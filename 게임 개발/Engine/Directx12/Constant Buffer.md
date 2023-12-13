# Constant Buffer ( 상수 버퍼 )

![image-20231208164343655](../../../image/image-20231208164343655.png)

## 상수 버퍼란?

Constant Buffer (상수 버퍼) 는 그래픽 프로그래밍에서 사용되는 중요한 개념 중 하나이다.

GPU에서 쉐이더에 전달되는 데이터를 저장하는 데 사용되며, 특히 상수값들을 저장하기 위한 목적으로 설계되어 있다.

상수 버퍼는 프로그래머가 쉐이더 코드에서 사용할 수 있는 상수 데이터를 정의하고 전달하는데 사용ehlsek.

## 상수 버퍼를 사용하는 단계

1. **상수 버퍼 정의 및 생성**  : 프로그램에서 사용할 상수 데이터의 구조를 정의하고, 이를 상수 버퍼로 생성한다.

   ```hlsl
   cbuffer MyConstantBuffer
   {
   	float4x4 worldMatrix;
   	float3 cameraPosition;
   	float time;
   };
   ```

   `cbuffer` 키워드를 사용하여 상수 버퍼를 정의하고, 그 내부에 상수 데이터의 구조를 선언한다.

2. **상수 버퍼 갱신** : 프로그램이 실행되는 동안, 프로그램에서는 필요할 때마다 상수 버퍼를 업데이트하여 GPU에 새로운 데이터를 전달한다.

   ```c++
   // 상수 버퍼 생성
   Microsoft::WRL::ComPtr<ID3D12Resource> constantBuffer;
   // ...상수 버퍼 초기화 등의 코드...
   
   // 상수 버퍼 갱신
   MyConstantBuffer cbData;
   cbData.worldMatrix = //...;
   cbData.camerPosition = //...;
   cbData.time = //...;
       
   // 상수 버퍼를 GPU에 업데이트
   void* pMappedData;
   constantBuffer->Map(0, nullptr, &pMappedData);
   memcpy(pMappedData, &cbData, sizeof(myConstantBuffer));
   constantBuffer->Unmap(0, nullptr);
   ```

   C++ 코드에서는 상수 버퍼를 생성하고, 필요한 때마다 갱신한다. 상수 버퍼를 GPU에 업데이트하기 위해 메모리를 매핑하고 데이터를 복사한 후 매핑을 해제하는 과정을 거친다.

3. **쉐이더에서 상수 버퍼 사용** : 쉐이더에서는 상수 버퍼에 정의된 데이터를 사용하여 그래픽 효과를 계산한다.

   ```hlsl
   float4 main(vs_input input) : SV_POSITION
   {
   	// 상수 버퍼에서 데이터 읽기
   	float4x4 worldMatrix = MyConstantBuffer.wordlMatrix;
   	float3 cameraPosition = MyConstantBuffer.cameraPosition;
   	float time = MyCOnstantBuffer.time;
   	
   	// 쉐이더 계산에 상수 데이터 사용
   	// ...
   }
   ```

   쉐이더에서는 상수 버퍼에서 필요한 데이터를 읽어와 사용한다.

DirectX 12에서 상수 버퍼는 성능 향상을 위해 최적화되어 있으며, 상수 데이터의 변화가 적은 경우에도 효율적으로 처리할 수 있도록 설계되어 있다. 이를 통해 그래픽 애플리케이션에서 더 나은 성능을 얻을 수 있다.

