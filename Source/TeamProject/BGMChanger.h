// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BGMChanger.generated.h"

UCLASS()
class TEAMPROJECT_API ABGMChanger : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Sound)
		class USoundBase* BGM_InGame;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Sound)
		class USoundBase* BGM_VSElite;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Sound)
		class USoundBase* BGM_VSBoss;

	class UAudioComponent* CurrentBGM;

public:	
	// Sets default values for this actor's properties
	ABGMChanger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool IsCurrentBGMValid();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
		void ChangeToInGameMusic();
	UFUNCTION(BlueprintCallable)
		void ChangeToVSEliteMusic();
	UFUNCTION(BlueprintCallable)
		void ChangeToVSBossMusic();
	UFUNCTION(BlueprintCallable)
		void FadeOutCurrentBGM(float FadeOutDuration);
	UFUNCTION(BlueprintCallable)
		void FadeInCurrentBGM(float FadeInDuration);
};
