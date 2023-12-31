# Rasterization

## 레스터라이제이션

그래픽스 파이프라인의 일부로, 3D 모델의 기하학적 형상을 2D 이미지로 변환하는 프로세스이다. 이 과정에서는 화면 상에 픽셀들을 생성하고, 이들 픽셀에 대응하는 정점들과 프래그먼트(색상 정보 등) 의 값을 계산한다. 레스터라이제이션은 버텍스 쉐이더에서 생성된 정ㅈ머 데이터를 가지고 각 프리미티브(점, 선, 삼각형 등)를 화면에 표시할 수 있는 픽셀로 변환된다.

## 레스터라이제이션의 주요 단계

1. **클리핑(Clip Space To Screen Space)**
   - 버텍스 쉐이더에서 생성된 정점 데이터는 클립 공간에서 정의된다. 이 정점 데이터는 가시 부피(뷰 포맷) 안에 있는지 확인하고, 범위를 벗어나는 부분은 제거 된다.
2. **프래그먼트 생성(Fragment Generation)**
   - 클리핑된 정점 데이터를 기반으로 프래그먼트를 생성한다. 프래그먼트는 픽셀의 위치와 해당 위치에 대응하는 정점의 정보를 가지고 있다.
3. **깊이 테스트(Depth Test) 및 스텐실 테스트(Stencil Test)**
   - 레스터라이제이션된 프래그먼트는 보간을 통해 프래그먼트의 값이 정점에서 계산된 값으로 적절하게 보간된다. 이러한 보간은 텍스처 좌표, 색상, 법선 벡터 등과 같은 프래그먼트에 관련된 데이터에 적용된다.
4. **픽셀 색상 계산(Pixel Color Calculation)**
   - 픽셀의 최종 색상은 픽셀 쉐이더에서 계산된다. 픽셀 쉐이더는 보간된 데이터와 텍스처 매핑, 조명 등을 이용하여 픽셀의 최종 색상을 결정한다.
5. **블렌딩(Blending) 및 출력(Output)**
   - 최종적으로 계산된 픽셀의 색상은 블렌딩 단계에서 다른 렌더 타겟에 쓰여질 색상과 결합된다. 이후, 결과는 화면에 출력되어 최종 이미지를 생성한다.

레스터라이제이션은 그래픽스에서 3D 모델을 2D 이미지로 변환하는 핵심 단계중 하나이며, 이 단계에서 생성된 이미지가 화면에 표시된다.