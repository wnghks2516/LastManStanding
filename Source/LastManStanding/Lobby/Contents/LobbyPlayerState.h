// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "LobbyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class LASTMANSTANDING_API ALobbyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bFlipFlopToggle = false;

	UFUNCTION(NetMulticast,Reliable)
	void Multicast_Ready();
private:
	UFUNCTION()
	void OnRep_NicknameChange();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	bool Ready;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, ReplicatedUsing = OnRep_NicknameChange)
	FText Nickname;


public:
	UFUNCTION(BlueprintCallable)
	void RefreshLobbyUI();
	UFUNCTION(BlueprintImplementableEvent)
	void BP_RefreshLobbyUI();


public:

	

};
