// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C03_Spawner.generated.h"

UCLASS()
class UNREALGAME_API AC03_Spawner : public AActor
{
	GENERATED_BODY()
	
private:
	//TSubclassOf �ش��ڷ��� ���漱��
	//���÷���
	//�ڷ����� Ÿ���� ������ �ٷ� �� �ֵ��� ���ִ� ���
	//�������ͻ�ӹ��� Ŭ������ ����Ҽ� �̾��� ����

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AC02_SpawnActor> SpawnClass[3];

		//UClass* SpanwClass;
		//UClass�� �𸮾� ���Ŭ��������

public:	
	AC03_Spawner();

protected:
	virtual void BeginPlay() override;

private:
	//���漱��
	class AC02_SpawnActor* SpawnActors[3];

};
