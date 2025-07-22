// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerState.h"
#include "Net/UnrealNetwork.h"


void ALobbyPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyPlayerState, Ready);
	DOREPLIFETIME(ALobbyPlayerState, Nickname);
}

void ALobbyPlayerState::OnRep_NicknameChange()
{
	RefreshLobbyUI();
}

void ALobbyPlayerState::RefreshLobbyUI()
{
	BP_RefreshLobbyUI();
}
