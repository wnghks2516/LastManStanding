// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.generated.h"

class UVerticalBox;
class UButton;
class ULobbyUserWidget;
class ALobbyPlayerState;
/**
 * 
 */
UCLASS()
class LASTMANSTANDING_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	//virtual bool Initialize() override;

	//UFUNCTION(BlueprintCallable)
	//void SetInfo();
	//UFUNCTION(BlueprintCallable)
	//void RefreshUI();



protected:
	UFUNCTION(BlueprintCallable,BlueprintPure)
	TArray<ALobbyPlayerState*> GetLobbyPlayerState();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ALobbyPlayerState* GetLobbyPlayerStateAtIndex(int32 Inindex);


protected:
	UPROPERTY(BlueprintReadWrite,meta=(BindWidget))
	TObjectPtr<UVerticalBox> UserList;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> Btn_GameConfig;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> Btn_Close;
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ULobbyUserWidget> ULobbyUserWidgetClass;

	UPROPERTY(BlueprintReadWrite)
	TArray<TObjectPtr<ULobbyUserWidget>> LobbyUsers;

};
