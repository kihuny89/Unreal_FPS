// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C05_MulticastTrigger.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiLightBegineOverlap, int32, FLinearColor);

UCLASS()
class UNREALGAME_API AC05_MulticastTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	AC05_MulticastTrigger();

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;
	UPROPERTY(VisibleDefaultsOnly)
		class UBoxComponent* Box;
	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;


protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
		void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
public:
	FMultiLightBegineOverlap OnMultiLightBegineOverlap;

};
