// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Save_Manager.generated.h"

UCLASS()
class SENTIENTAGENTS_API USave_Manager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Save Slot name ex: Slot1
	UPROPERTY(BlueprintReadWrite, Category = "SaveSystem")
	FString SaveSlotName = TEXT("DefaultSaveSlot");

	// Save world current state
	UFUNCTION(BlueprintCallable, Category = "SaveSystem")
	void SaveGame();

	// Load game state from disk and aplly to the world state
	UFUNCTION(BlueprintCallable, Category = "SaveSystem")
	void LoadGame();
};
