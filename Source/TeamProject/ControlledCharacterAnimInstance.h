// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ControlledCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_API UControlledCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UControlledCharacterAnimInstance();
protected:
	UPROPERTY(BlueprintReadOnly)
	class AControlledCharacter* Owner;

	UPROPERTY(BlueprintReadOnly)
	float AngleBetweenMoveDirAndForward;
	UPROPERTY(BlueprintReadOnly)
	float Speed;
	UPROPERTY(BlueprintReadOnly)
	float RunAnimationPlayRate;
	UPROPERTY(BlueprintReadOnly)
	TArray<float> DebuffTime;

protected:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
