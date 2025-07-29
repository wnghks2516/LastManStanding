// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Interfaces/OnlineSessionDelegates.h"
#include "OnelineSessionsSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class LASTMANSTANDING_API UOnelineSessionsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UOnelineSessionsSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

public:
	UFUNCTION(BlueprintCallable)
	void CreateSession();

private:
	void OnCreate(FName SessionName, bool bWasSuccessful);
private:
	IOnlineSessionPtr SessionManager;

	FOnCreateSessionCompleteDelegate CreateCompleteDelegate;
	FDelegateHandle CreateCompleteDelegateHandle;
};
