// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomItemWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void URoomItemWidget::SetInfo(FBlueprintSessionResult InSessionResult)
{
	Result = InSessionResult;
	RefreshUI();
}

void URoomItemWidget::RefreshUI()
{
	FString RoomName;
	Result.OnlineResult.Session.SessionSettings.Get(FName("Room_Name"), OUT RoomName);
	Txt_RoomName->SetText(FText::FromString(RoomName));

	FString MapName;
	Result.OnlineResult.Session.SessionSettings.Get(FName("Map_Name"), OUT MapName);
	Txt_MapName->SetText(FText::FromString(MapName));

	const int32 CurrentPlayer = Result.OnlineResult.Session.SessionSettings.NumPublicConnections - Result.OnlineResult.Session.NumOpenPublicConnections;
	const int32 MaxPlayer = Result.OnlineResult.Session.SessionSettings.NumPublicConnections ;
	FString PlayerCountString = FString::Printf(TEXT(" %d / %d"), CurrentPlayer, MaxPlayer);
	Txt_PlayerCount->SetText(FText::FromString(PlayerCountString));
;}