// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C02_DrawDebug.generated.h"

UCLASS()
class UNREALGAME_API AC02_DrawDebug : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FVector InitLocation[5];
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FBox Box;
	UPROPERTY(EditAnywhere, Category = "DrawDebug")
		FTransform Transform;

public:	

	AC02_DrawDebug();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	FVector Location[5];

};
