// Fill out your copyright notice in the Description page of Project Settings.


#include "C02_LineTrace.h"
#include "Global.h"
#include "CPlayer.h"
#include "C01_Cylinder.h"
#include "Components/TextRenderComponent.h"

AC02_LineTrace::AC02_LineTrace()
{
	PrimaryActorTick.bCanEverTick = true;
	CHelpers::CreateComponent<USceneComponent>(this, &Scene, "Scene");
	CHelpers::CreateComponent<UTextRenderComponent>(this, &Text, "Text", Scene);

	Text->SetRelativeLocation(FVector(0, 0, 100));
	Text->SetRelativeRotation(FRotator(0, 180, 0));
	Text->SetRelativeScale3D(FVector(2));
	Text->TextRenderColor = FColor::Red;
	Text->HorizontalAlignment = EHorizTextAligment::EHTA_Center;
	Text->Text = FText::FromString(GetName());


}


void AC02_LineTrace::BeginPlay()
{
	Super::BeginPlay();

	CHelpers::FindActors<AC01_Cylinder>(GetWorld(), Cylinders);
	OnTraceResult.AddDynamic(this, &AC02_LineTrace::StarJump);

}


void AC02_LineTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector start = Cylinders[0]->GetActorLocation();
	FVector end = Cylinders[1]->GetActorLocation();

	//DrawDebugLine
	{
		start.Z -= 10;
		end.Z -= 10;
		DrawDebugLine(GetWorld(), start, end, FColor::Yellow, false);
	}

	//LineTrace
	{
		start.Z += 10;
		end.Z += 10;

		TArray<AActor*> ignoreActors;
		ignoreActors.Add(Cylinders[0]);
		ignoreActors.Add(Cylinders[1]);

		FHitResult hitResult;

		if (UKismetSystemLibrary::LineTraceSingleByProfile(GetWorld(), start, end, "Pawn", false, ignoreActors, EDrawDebugTrace::ForOneFrame, hitResult, true, FLinearColor::Green, FLinearColor::Red))
		{
			if (OnTraceResult.IsBound())
			{
				FLinearColor color;
				color.R = UKismetMathLibrary::RandomFloatInRange(0, 1);
				color.G = UKismetMathLibrary::RandomFloatInRange(0, 1);
				color.B = UKismetMathLibrary::RandomFloatInRange(0, 1);
				color.A = UKismetMathLibrary::RandomFloatInRange(0, 1);

				OnTraceResult.Broadcast(hitResult.GetActor(), color);
			}
		}

	}


}

void AC02_LineTrace::StarJump(AActor* InActor, FLinearColor InColor)
{
	ACPlayer* player = Cast<ACPlayer>(InActor);
	CheckNull(player);

	player->Jump();
}

void AC02_LineTrace::RestoreColor(ACPlayer* InPlayer)
{
	InPlayer->ChangeColor(FLinearColor(1, 1, 1));
}

