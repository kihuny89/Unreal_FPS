// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C04_Explosion.generated.h"

UCLASS()
class UNREALGAME_API AC04_Explosion : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleDefaultsOnly)
		class UParticleSystemComponent* Particle;

public:	
	AC04_Explosion();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
		void ActorBeginOverlap(AActor* OnverlappedActor, AActor* OtherActor);



};
