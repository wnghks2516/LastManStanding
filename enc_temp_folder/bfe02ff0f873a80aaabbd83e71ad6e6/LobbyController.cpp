// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyController.h"
#include "LobbyPlayerState.h"
#include "LobbyGameMode.h"
#include "Kismet/GameplayStatics.h"

void ALobbyController::Server_HandleReadyButton_Implementation()
{
	if (HasAuthority()==false)
		return;

	ALobbyPlayerState* LobbyPlayerState = Cast<ALobbyPlayerState>(GetPawn()->GetPlayerState());
	if (LobbyPlayerState)
		LobbyPlayerState->Multicast_Ready();

	ALobbyGameMode* LobbyGamemode = Cast<ALobbyGameMode>(UGameplayStatics::GetGameMode(this));
	
	
	
}

void ALobbyController::Server_HandleChangeNickname_Implementation(const FText& InNickname)
{
	if (HasAuthority() == false)
		return;

	ALobbyPlayerState* LobbyPlayerState = Cast<ALobbyPlayerState>(GetPawn()->GetPlayerState());
	if (LobbyPlayerState)
		LobbyPlayerState->Nickname = InNickname;
}
