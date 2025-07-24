// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "LobbyPlayerState.h"


//bool ALobbyGameMode::IsEverybodyReady()
//{
//	AGameStateBase* GameStates = UGameplayStatics::GetGameState(this);
//	if (GameStates != nullptr)
//	{
//		for (APlayerState* PlayerState : GameState->PlayerArray)
//		{
//			ALobbyPlayerState* LobbyPlayerState = Cast<ALobbyPlayerState>(PlayerState);
//			if (LobbyPlayerState == nullptr) {
//				continue;
//			}
//			if (LobbyPlayerState->Ready == false)
//				return false;
//		}
//		return true;
//	}
//	else
//		return false;
//}
