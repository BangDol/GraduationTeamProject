// Copyright Epic Games, Inc. All Rights Reserved.

#include "TeamProjectGameMode.h"
#include "TeamProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "RoguelikeSaveGame.h"
#include "Kismet/GameplayStatics.h"

ATeamProjectGameMode::ATeamProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Object/Player/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}