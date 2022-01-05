// Fill out your copyright notice in the Description page of Project Settings.


#include "C04_Explosion.h"
#include "Global.h"
#include "Particles/ParticleSystemComponent.h"


AC04_Explosion::AC04_Explosion()
{
	CHelpers::CreateComponent<UParticleSystemComponent>(this, &Particle, "Particle");

	UParticleSystem* particle;
	CHelpers::GetAsset<UParticleSystem>(&particle, "ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Gruntling/Bomber/P_FireBombExplosion.P_FireBombExplosion'");
	Particle->SetTemplate(particle);
	Particle->bAutoActivate = false;


}


void AC04_Explosion::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC04_Explosion::ActorBeginOverlap(AActor* OnverlappedActor, AActor* OtherActor)
{
	Particle->ResetParticles();
	Particle->SetActive(true);

	FVector start = GetActorLocation();
	FVector end = FVector(start.X, start.Y, start.Z + 10);

	TArray<TEnumAsByte<EObjectTypeQuery>> queries;
	queries.Add(EObjectTypeQuery::ObjectTypeQuery4);

	TArray<AActor*> ignoreActors;

	TArray<FHitResult> hitResults;

	if (UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), start, end, 200, queries, false, ignoreActors, EDrawDebugTrace::ForOneFrame, hitResults, true))
	{
		for (const FHitResult& hitResut : hitResults)
		{
			UStaticMeshComponent* meshComponent = Cast<UStaticMeshComponent>(hitResut.GetActor()->GetRootComponent());
			if (!!meshComponent)
				meshComponent->AddRadialImpulse(GetActorLocation(), 1000, meshComponent->GetMass() * 700.0f, ERadialImpulseFalloff::RIF_Linear);
		}
	}

}

