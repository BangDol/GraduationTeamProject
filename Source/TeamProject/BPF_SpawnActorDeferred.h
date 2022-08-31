// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPF_SpawnActorDeferred.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_API UBPF_SpawnActorDeferred : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	class AActor* SpawnActorDeferred(UClass* Class, FTransform const& Transform, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride);
	UFUNCTION(BlueprintCallable)
	void FinishSpawningActor(AActor* Actor, const FTransform& SpawnTransform);
};
