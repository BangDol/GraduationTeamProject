// Fill out your copyright notice in the Description page of Project Settings.

#include "TitleGameMode.h"
#include "RoguelikeSaveGame.h"
#include "Weapon.h"
#include "Kismet/GameplayStatics.h"

ATitleGameMode::ATitleGameMode()
{
	DefaultPawnClass = nullptr;

}

void ATitleGameMode::StartPlay()
{
	Super::StartPlay();

	if (UGameplayStatics::DoesSaveGameExist("MySaveGame", 0))
	{
		Load();
	}
	else
	{
		Save();
	}
}

//세이브 데이터 초기값 설정
void ATitleGameMode::Save()
{
	URoguelikeSaveGame* SaveGameInstance = Cast<URoguelikeSaveGame>(UGameplayStatics::CreateSaveGameObject(URoguelikeSaveGame::StaticClass()));

	if (SaveGameInstance)
	{
		//Save file Data
		SaveGameInstance->SaveSlotName = "MySaveGame";
		SaveGameInstance->SaveIndex = 0;

		//Save data
		SaveGameInstance->PlayerGold = 0;

		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::MaxHP, 200.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::Speed, 500.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::Critical, 0.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::Armor, 0.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::AD, 12.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::ExpIncreaseRate, 0.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::Burn, 0.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::Electric, 0.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::Freezing, 0.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::SwordAD, 1.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::WandAD, 1.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::ShieldAD, 1.f);
		SaveGameInstance->UpgradeFactor.Add(EUpgradeFactor::TwoHandAD, 1.f);
	}

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->SaveIndex);
}

void ATitleGameMode::Load()
{
	URoguelikeSaveGame* LoadGameInstance = Cast<URoguelikeSaveGame>(UGameplayStatics::CreateSaveGameObject(URoguelikeSaveGame::StaticClass()));

	if (LoadGameInstance)
	{
		//Load file Data
		//로드 시 이름과 인덱스에 주의
		LoadGameInstance->SaveSlotName = "MySaveGame";
		LoadGameInstance->SaveIndex = 0;

		LoadGameInstance = Cast<URoguelikeSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->SaveIndex));
	}
}

int ATitleGameMode::GetPlayerGold()
{
	URoguelikeSaveGame* LoadGameInstance = Cast<URoguelikeSaveGame>(UGameplayStatics::CreateSaveGameObject(URoguelikeSaveGame::StaticClass()));

	if (LoadGameInstance)
	{	
		LoadGameInstance = Cast<URoguelikeSaveGame>(UGameplayStatics::LoadGameFromSlot("MySaveGame", 0));

		int PlayerGold = LoadGameInstance->PlayerGold;

		return PlayerGold;
	}

	return 0;
}
