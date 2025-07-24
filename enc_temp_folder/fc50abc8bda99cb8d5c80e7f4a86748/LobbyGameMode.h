// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class LASTMANSTANDING_API ALobbyGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent)
	void BP_TryStartGame();

	

	/*UFUNCTION(BlueprintCallable,BlueprintPure)
	bool IsEverybodyReady();*/

public:
	/*FString LevelName = TEXT("Level_Fountain");
	int32 NicknameIndex;*/
	
	
};
