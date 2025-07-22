// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyWidget.h"
#include "LobbyUserWidget.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "Lobby/Contents/LobbyPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/GameState.h"


bool ULobbyWidget::Initialize()
{
	if (Super::Initialize() == false)
		return false;

	SetInfo();


	return true;
}

void ULobbyWidget::SetInfo()
{
	//Clear Children

	LobbyUsers.Empty();

	//Create Child Widget

	for (int32 i = 0; i < 10; i++)
	{
		if (ULobbyUserWidgetClass == nullptr)
			continue;

		ULobbyUserWidget* ChildWidget = CreateWidget<ULobbyUserWidget>(GetWorld(), ULobbyUserWidgetClass);
		if (ChildWidget == nullptr)
			continue;
		UserList->AddChildToVerticalBox(ChildWidget);
		LobbyUsers.Add(ChildWidget);
	}

	RefreshUI();
}

void ULobbyWidget::RefreshUI()
{
	AGameStateBase* GameState = UGameplayStatics::GetGameState(this);
	if(GameState == nullptr)
	{
		return;
	}

	TArray<ALobbyPlayerState*> LobbyPlayerStates = GetLobbyPlayerStates();
	const int32 PlayerLengh = LobbyPlayerStates.Num();

	for (int32 i = 0; i < LobbyUsers.Num(); i++)
	{
		const int32 Index = i;

		if (Index < PlayerLengh)
		{
			LobbyUsers[Index]->SetVisibility(ESlateVisibility::Visible);
			ALobbyPlayerState* PlayerState = GetLobbyPlayerStateAtIndex(Index);
			LobbyUsers[Index]->SetInfo(PlayerState);
		}
		else
		{
			LobbyUsers[Index]->SetVisibility(ESlateVisibility::Collapsed);
		}
	}

	if (UKismetSystemLibrary::IsServer(this))
		Btn_GameConfig->SetVisibility(ESlateVisibility::Visible);
	else
		Btn_GameConfig->SetVisibility(ESlateVisibility::Hidden);
}

TArray<ALobbyPlayerState*> ULobbyWidget::GetLobbyPlayerStates()
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
	
	TArray<ALobbyPlayerState*> LobbyPlayerStates = GetLobbyPlayerStates();
	
	
	if(Inindex < LobbyPlayerStates.Num())
		return LobbyPlayerStates[Inindex];

	return nullptr;
}
