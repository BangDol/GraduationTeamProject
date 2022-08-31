// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "RoguelikeSaveGame.generated.h"

UENUM(BlueprintType)
enum class EUpgradeFactor : uint8
{
	MaxHP = 0 UMETA(DisplayName = "MaxHP"),
	Speed UMETA(DisplayName = "Speed"),
	Critical UMETA(DisPlayName = "CriticalRate"),
	Armor UMETA(DisplayName = "Armor"),
	ExpIncreaseRate UMETA(DisplayName = "ExpIncreaseRate"),
	Burn UMETA(DisplayName = "Burn"),
	Freezing UMETA(DisplayName = "Freezing"),
	Electric UMETA(DisplayName = "Electric"),
	SwordAD UMETA(DisplayName = "SwordAD"),
	WandAD UMETA(DisplayName = "WandAD"),
	ShieldAD UMETA(DisplayName = "ShieldAD"),
	TwoHandAD UMETA(DisplayName = "TwoHandAD"),
	AD UMETA(DisplayName = "AD"),

	Count  UMETA(DisplayName = "Count")
};

UCLASS()
class TEAMPROJECT_API URoguelikeSaveGame : public USaveGame
{
	GENERATED_BODY()
	
	//UPROPERTY를 사용하지 않으면 데이터가 저장되지 않는다
public:
	//두 변수는 SaveGame을 이용하여 저장할 때 필요한 변수이므로 꼭 넣는다
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		FString SaveSlotName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		int32 SaveIndex;

	//저장할 데이터
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		int PlayerGold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		TMap<EUpgradeFactor, float> UpgradeFactor;
};
