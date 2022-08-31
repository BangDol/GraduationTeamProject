// Fill out your copyright notice in the Description page of Project Settings.


#include "BPF_SpawnActorDeferred.h"
#include "Kismet/GameplayStatics.h"

AActor* UBPF_SpawnActorDeferred::SpawnActorDeferred(UClass* Class,
	FTransform const& Transform, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride)
{
	return GetWorld()->SpawnActorDeferred<AActor>(Class, Transform, nullptr, nullptr, CollisionHandlingOverride);
}

void UBPF_SpawnActorDeferred::FinishSpawningActor(AActor* Actor, const FTransform& SpawnTransform)
{
	UGameplayStatics::FinishSpawningActor(
		Actor,
		SpawnTransform
	);
}
