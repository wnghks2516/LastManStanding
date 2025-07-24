// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyController.generated.h"

/**
 * 
 */
UCLASS()
class LASTMANSTANDING_API ALobbyController : public APlayerController
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_HandleReadyButton();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Server_HandleChangeNickname(const FText& InNickname);
};
