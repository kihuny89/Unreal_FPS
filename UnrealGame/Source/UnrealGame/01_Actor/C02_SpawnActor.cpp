// Fill out your copyright notice in the Description page of Project Settings.


#include "C02_SpawnActor.h"
#include "Global.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Materials/MaterialInstanceDynamic.h"

AC02_SpawnActor::AC02_SpawnActor()
{
	// �ڷ��� ���ø� ���ø��̸�
	//�Ϲ������� �������ϰ� ��ġ���ָ� ���ϴ�.

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	//�޽��⺻�ڷ���/����������/�޽�����/ť��.�ĺ���
	//StaticMesh'/Game/Meshes/M_Cube.M_Cube'

	//�����ڸ� �����Ŭ������ ��Ƶδ¼�::������Ʈã����
	//<�ڷ���ã��>
	//TEXT()�����ڵ� ���
	//L ��Ƽ����Ʈ ����1 �ѱ�2
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
	//c++������ MeterialInstance�� UMaterialInstanceConstant�� ǥ�� 
	//�����ε��� �ؾߵǱ� ������ ����Ŭ���� ���Ұ�
	//�����ڰ� �ƴѰ����� �����Ҵ���� StaticLoadObject
	//UObjectsms �ֻ��� �ڷ��� �̹Ƿ� ����� �ڷ����� ĳ�����ؼ� ����ϸ� �ȴ�.
	
	//UObject* obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), NULL, L"MaterialInstanceConstant'/Game/Meterial/M_Mesh_Inst.M_Mesh_Inst'");
	//UMaterialInstanceConstant* material = Cast<UMaterialInstanceConstant>(obj);//ĳ���� �����ϸ� NULL

	//����Ŭ������ ����غ���
	UMaterialInstanceConstant* material; //�𸮾󿡼��� ������ ���������� �ڵ� �ʱ�ȭ���ش�. NULL
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
