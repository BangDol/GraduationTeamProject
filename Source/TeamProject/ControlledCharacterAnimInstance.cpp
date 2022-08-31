// Fill out your copyright notice in the Description page of Project Settings.

#include "ControlledCharacterAnimInstance.h"
#include "ControlledCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UControlledCharacterAnimInstance::UControlledCharacterAnimInstance()
{
	DebuffTime.Init(0.f, (int)EDebuff::Count);
}

void UControlledCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Owner = Cast<AControlledCharacter>(TryGetPawnOwner());
	DebuffTime.Init(0.f, (int)EDebuff::Count);
}

void UControlledCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(Owner))
	{	
		FVector Movedir = Owner->GetVelocity();
		Movedir.Normalize();
		FVector Forward = Owner->GetActorForwardVector();
		
		float Angle = FMath::Acos(FVector::DotProduct(Movedir, Forward)) * (180.f / PI);
				
		if (FVector::DotProduct(FVector::UpVector, FVector::CrossProduct(Movedir, Forward)) > 0.f)
		{
			Angle *= -1.f;
		}
		AngleBetweenMoveDirAndForward = FMath::Lerp(AngleBetweenMoveDirAndForward, Angle, 0.05f);

		if(Owner->IsWalk)
			Speed = FMath::Lerp(Speed, Owner->GetVelocity().Size() / Owner->GetCharacterMovement()->GetMaxSpeed() / 2.f, 0.05f);
		else
			Speed = FMath::Lerp(Speed, Owner->GetVelocity().Size() / Owner->GetCharacterMovement()->GetMaxSpeed(), 0.05f);

		RunAnimationPlayRate = Owner->RunAnimationPlayRate;
		for (size_t i = 0; i < (int)EDebuff::Count; i++)
		{
			DebuffTime[i] = Owner->DebuffTime[i];
		}
	}
	else
	{
		Owner = Cast<AControlledCharacter>(TryGetPawnOwner());
	}
}