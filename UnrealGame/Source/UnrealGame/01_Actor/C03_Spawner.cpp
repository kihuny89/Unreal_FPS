// Fill out your copyright notice in the Description page of Project Settings.


#include "C03_Spawner.h"
#include "Global.h"
#include "C02_SpawnActor.h"

// Sets default values
AC03_Spawner::AC03_Spawner()
{


}

void AC03_Spawner::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < 3; i++)
	{
		FTransform transform;
		FVector location = GetActorLocation();
		transform.SetLocation(FVector(location.X + i * 400, location.Y, location.Z));
		SpawnActors[i] = GetWorld()->SpawnActor<AC02_SpawnActor>(SpawnClass[i], transform);
	}


}
