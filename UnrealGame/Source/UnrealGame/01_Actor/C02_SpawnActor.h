// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_SpawnActor.generated.h"

UCLASS()
class UNREALGAME_API AC02_SpawnActor : public AActor
{
	GENERATED_BODY()
	
protected:
	//ÄÄÆ÷³ÍÆ®
	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

public:	
	
	AC02_SpawnActor();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void ChangeColor();

private:
	class UMaterialInstanceDynamic* Material;


};
