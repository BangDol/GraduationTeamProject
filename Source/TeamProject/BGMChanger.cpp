// Fill out your copyright notice in the Description page of Project Settings.


#include "BGMChanger.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"

// Sets default values
ABGMChanger::ABGMChanger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABGMChanger::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(BGM_InGame))
	{
		CurrentBGM = UGameplayStatics::SpawnSound2D(GetWorld(), BGM_InGame);
		FadeInCurrentBGM(5.0f);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("BGM_VSInGame is invalid"));
	}
}

bool ABGMChanger::IsCurrentBGMValid()
{
	if (CurrentBGM != nullptr)
	{
		return true;
	}

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("CurrentBGM is nullptr"));

	return false;
}

// Called every frame
void ABGMChanger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABGMChanger::ChangeToInGameMusic()
{
	FadeOutCurrentBGM(1.f);

	if (IsValid(BGM_InGame))
	{
		CurrentBGM = UGameplayStatics::SpawnSound2D(GetWorld(), BGM_InGame);

		FadeInCurrentBGM(2.f);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("BGM_VSInGame is invalid"));
	}
}

void ABGMChanger::ChangeToVSEliteMusic()
{
	FadeOutCurrentBGM(1.f);

	if (IsValid(BGM_VSElite))
	{
		CurrentBGM = UGameplayStatics::SpawnSound2D(GetWorld(), BGM_VSElite);
		//CurrentBGM->FadeIn(0.3f);
		FadeInCurrentBGM(0.3f);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("BGM_VSElite is invalid"));
	}
}

void ABGMChanger::ChangeToVSBossMusic()
{
	FadeOutCurrentBGM(1.f);

	if (IsValid(BGM_VSBoss))
	{
		CurrentBGM = UGameplayStatics::SpawnSound2D(GetWorld(), BGM_VSBoss);

		FadeInCurrentBGM(0.3f);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("BGM_VSBoss is invalid"));
	}
}

void ABGMChanger::FadeOutCurrentBGM(float FadeOutDuration)
{
	if (!IsCurrentBGMValid())
	{
		return;
	}

	CurrentBGM->FadeOut(FadeOutDuration, 0.0f);
}

void ABGMChanger::FadeInCurrentBGM(float FadeInDuration)
{
	if (!IsCurrentBGMValid())
	{
		return;
	}

	CurrentBGM->FadeIn(FadeInDuration);
}
