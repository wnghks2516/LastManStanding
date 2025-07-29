// Fill out your copyright notice in the Description page of Project Settings.


#include "OnelineSessionsSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Online/OnlineSessionNames.h"
#include "kismet/Gameplaystatics.h"

UOnelineSessionsSubsystem::UOnelineSessionsSubsystem()
	: CreateCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreate))
{

}

void UOnelineSessionsSubsystem::CreateSession()
{
	//SessionManager->OnCreateSessionCompleteDelegates.AddUObject(this, &UOnelineSessionsSubsystem::OnCreate);
	
	CreateCompleteDelegateHandle = SessionManager->AddOnCreateSessionCompleteDelegate_Handle(CreateCompleteDelegate);

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

void UOnelineSessionsSubsystem::OnCreate(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		UGameplayStatics::OpenLevel(this, "Lobby", true, FString("listen"));
	}

	SessionManager->ClearOnCreateSessionCompleteDelegate_Handle(CreateCompleteDelegateHandle);
}



void UOnelineSessionsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if (OnlineSubsystem == nullptr)
		return;

	SessionManager = OnlineSubsystem->GetSessionInterface();
	if (SessionManager == nullptr)
		return;

}
