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
	//TSubclassOf 해당자료형 전방선언
	//리플렉션
	//자료형의 타입을 변수로 다룰 수 있도록 해주는 기능
	//스폰액터상속받은 클래스만 사용할수 이쑈게 제한

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class AC02_SpawnActor> SpawnClass[3];

		//UClass* SpanwClass;
		//UClass는 언리얼 모든클래스가능

public:	
	AC03_Spawner();

protected:
	virtual void BeginPlay() override;

private:
	//전방선언
	class AC02_SpawnActor* SpawnActors[3];

};
