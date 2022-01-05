// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C01_Property.generated.h"

UCLASS()
class UNREALGAME_API AC01_Property : public AActor
{
	GENERATED_BODY()

private:
	//모든 값을 사용가능
	UPROPERTY(EditAnywhere)
		int A = 10;
	//배치된 애들만 사용가능
	UPROPERTY(EditInstanceOnly)
		int B = 20;
	//기본값 설정
	UPROPERTY(EditDefaultsOnly)
		int C = 30;

protected:
	//수정은 불가능한데 값확인 하고싶을대
	//블루프린트에서 접근가능
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int Test = 50;


public:	
	// Sets default values for this actor's properties
	AC01_Property();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

};
