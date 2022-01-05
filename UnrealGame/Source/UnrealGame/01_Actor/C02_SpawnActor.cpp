// Fill out your copyright notice in the Description page of Project Settings.


#include "C02_SpawnActor.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

AC02_SpawnActor::AC02_SpawnActor()
{
	// 자료형 템플릿 템플릿이름
	//일반적으로 변수명하고 일치해주면 편하다.

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	//메쉬기본자료형/컨텐츠폴더/메쉬폴더/큐브.식별자
	//StaticMesh'/Game/Meshes/M_Cube.M_Cube'

	//생성자를 도움될클래스를 모아두는속::오브젝트찾아줌
	//<자료형찾기>
	//TEXT()유니코드 방식
	//L 멀티바이트 영문1 한글2
	/*ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(L"StaticMesh'/Game/Meshes/M_Cube.M_Cube'");

	if (mesh.Succeeded())
		Mesh->SetStaticMesh(mesh.Object);*/
	
	UStaticMesh* mesh;
	CHelpers::GetAsset<UStaticMesh>(&mesh, "StaticMesh'/Game/Meshes/M_Cube.M_Cube'");
	Mesh->SetStaticMesh(mesh);

}

void AC02_SpawnActor::BeginPlay()
{
	Super::BeginPlay();
	//c++에서는 MeterialInstance가 UMaterialInstanceConstant로 표현 
	//동적로딩을 해야되기 때문에 헬퍼클래스 사용불가
	//생성자가 아닌곳에서 동적할당수는 StaticLoadObject
	//UObjectsms 최상위 자료형 이므로 사용할 자료형을 캐스팅해서 사용하면 된다.
	
	//UObject* obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), NULL, L"MaterialInstanceConstant'/Game/Meterial/M_Mesh_Inst.M_Mesh_Inst'");
	//UMaterialInstanceConstant* material = Cast<UMaterialInstanceConstant>(obj);//캐스팅 실패하면 NULL

	//헬퍼클래스로 사용해보기
	UMaterialInstanceConstant* material; //언리얼에서는 포인터 선언했을때 자동 초기화해준다. NULL
	CHelpers::GetAssetDynamic<UMaterialInstanceConstant>(&material, "MaterialInstanceConstant'/Game/Meterial/M_Mesh_Inst.M_Mesh_Inst'");

	Material = UMaterialInstanceDynamic::Create(material, this);
	Mesh->SetMaterial(0, Material);

	UKismetSystemLibrary::K2_SetTimer(this, "ChangeColor", 1.0f, true);
}

void AC02_SpawnActor::ChangeColor()
{
	FLinearColor color;

	color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
	color.A = 1.0f;

	Material->SetVectorParameterValue("Color", color);

}
