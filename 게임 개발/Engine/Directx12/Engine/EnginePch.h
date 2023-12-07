#pragma once

// 각종 include
#include <windows.h>
#include <tchar.h>
#include <memory>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <map>
using namespace std;

#include "d3dx12.h"
#include <d3d12.h>
#include <wrl.h>
#include <d3dcompiler.h>
#include <dxgi.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace Microsoft::WRL;

// 각종 lib
#pragma comment(lib, "d3d12")
#pragma comment(lib, "dxgi")
#pragma comment(lib, "dxguid")
#pragma comment(lib, "d3dcompiler")

// 각종 typedef
using int8		= __int8;
using int16		= __int16;
using int32		= __int32;
using int64		= __int64;
using uint8		= unsigned __int8;
using uint16	= unsigned __int16;
using uint32	= unsigned __int32;
using uint64	= unsigned __int64;
using Vec2		= XMFLOAT2;
using Vec3		= XMFLOAT3;
using Vec4		= XMFLOAT4;
using Matrix	= XMMATRIX;

enum
{
	SWAP_CHAIN_BUFFER_COUNT = 2,
};

struct WindowInfo
{
	HWND	hwnd; // 출력 윈도우
	int32	width; // 윈도우 가로 크기 (너비)
	int32	height; // 윈도우 세로 크기 (높이)
	bool	windowed; // 창모드 or 전체화면 여부
};

struct Vertex
{
	Vec3 pos;
	Vec4 color;
};

#define DEVICE		GEngine->GetDevice()->GetDevice()
#define CMD_LIST	GEngine->GetCommandQueue()->GetCmdList()

// extern이란?
// extern은 외부에 선언된 전역변수를 사용할 때 사용하는 키워드입니다.
extern unique_ptr<class Engine> GEngine;
