// Fill out your copyright notice in the Description page of Project Settings.


#include "C01_Log.h"
#include "Global.h"

AC01_Log::AC01_Log()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AC01_Log::BeginPlay()
{
	Super::BeginPlay();
	
	CLog::Print(10);
	CLog::Print(20,1);
	//같은 아이디면 30이 빠르게 지워진다.
	CLog::Print(30, 2, 20.0f);
	CLog::Print(40, 2, 20.0f);

	CLog::Print("Unreal Gameplay");
	CLog::Print(GetActorLocation());
	CLog::Print(GetActorRotation());


	CLog::Log(10);
	CLog::Log(PI);
	CLog::Log("Unreal Gameplay");
	CLog::Log(GetActorLocation());
	CLog::Log(GetActorRotation());

}

void AC01_Log::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Time += DeltaTime;
	CLog::Print(Time, 3);

}

