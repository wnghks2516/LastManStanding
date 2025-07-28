// Fill out your copyright notice in the Description page of Project Settings.


#include "OnelineSessionsSubsystem.h"
#include "Online/OnlineSessionNames.h"
#include "OnlineSessionSettings.h"
#include "OnlineSubsystem.h"


UOnelineSessionsSubsystem::UOnelineSessionsSubsystem()
{

}

void UOnelineSessionsSubsystem::CreateSession()
{
	FOnlineSessionSettings Settings;
	Settings.NumPublicConnections = 10;
	Settings.bShouldAdvertise = true;
	Settings.bAllowJoinInProgress = true;
	Settings.bIsLANMatch = true;
	Settings.bUsesPresence = true;
	Settings.bAllowJoinViaPresence = true;
	Settings.bUseLobbiesIfAvailable = true;

	const ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	SessionManager->CreateSession(*localPlayer->GetPreferredUniqueNetId(), NAME_GameSession, Settings);
}



void UOnelineSessionsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if (OnlineSubsystem == nullptr)
		return;

	SessionManager = OnlineSubsystem->GetSessionInterface();
	if (SessionManager == nullptr)
		return;

	FString SubsystemName = OnlineSubsystem->GetSubsystemName().ToString();
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Cyan, SubsystemName);
}
