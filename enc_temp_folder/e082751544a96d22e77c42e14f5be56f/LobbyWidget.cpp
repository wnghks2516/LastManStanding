// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidget.h"
#include "Lobby/Contents/LobbyPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/GameState.h"


TArray<ALobbyPlayerState*> ULobbyWidget::GetLobbyPlayerState()
{
	
	TArray<ALobbyPlayerState*> LobbyPlayerStates;
	if (AGameStateBase* GameState = UGameplayStatics::GetGameState(this))
	{
		for (APlayerState* PlayerState : GameState->PlayerArray)
		{
			ALobbyPlayerState* LobbyPlayerState = Cast<ALobbyPlayerState>(PlayerState);
			if (LobbyPlayerState == nullptr) {
				continue;
			}
			LobbyPlayerStates.Add(LobbyPlayerState);
		}
	}

	return LobbyPlayerStates;
}

ALobbyPlayerState* ULobbyWidget::GetLobbyPlayerStateAtIndex(int32 Inindex)
{
	
	TArray<ALobbyPlayerState*> LobbyPlayerStates = GetLobbyPlayerState();
	
	
	if(Inindex < LobbyPlayerStates.Num())
		return LobbyPlayerStates[Inindex];

	return nullptr;
}
