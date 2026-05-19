// Fill out your copyright notice in the Description page of Project Settings.


#include "Save_Manager.h"
#include "Save_Game.h"
#include "ISavableInterface.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

void USave_Manager::SaveGame()
{
	// 1. Create new save game instance Save_Game
	USave_Game* SaveGameInstance = Cast<USave_Game>(UGameplayStatics::CreateSaveGameObject(USave_Game::StaticClass()));
	if (!SaveGameInstance) return;

	// 2. search all actors in the world that implement the interface
	for (FActorIterator It(GetWorld()); It; ++It)
	{
		AActor* Actor = *It;
		if (Actor && Actor->GetClass()->ImplementsInterface(UISavableInterface::StaticClass()))
		{
			// secure call to interface (c++ or blueprint)
			IISavableInterface::Execute_OnSave(Actor, SaveGameInstance);
		}
	}

	// 3. this writes data on disk
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveSlotName, 0);
	UE_LOG(LogTemp, Warning, TEXT("Succeeded save in slot: %s"), *SaveSlotName);
}

void USave_Manager::LoadGame()
{
	// 1. Verify if exists a save before loading
	if (!UGameplayStatics::DoesSaveGameExist(SaveSlotName, 0))
	{
		UE_LOG(LogTemp, Error, TEXT("No save file found in slot: %s"), *SaveSlotName);
		return;
	}

	// 2. load object from disk
	USave_Game* SaveGameInstance = Cast<USave_Game>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (!SaveGameInstance) return;

	// 3. Its passes the data to all actors that implement the interface
	for (FActorIterator It(GetWorld()); It; ++It)
	{
		AActor* Actor = *It;
		if (Actor && Actor->GetClass()->ImplementsInterface(UISavableInterface::StaticClass()))
		{
			IISavableInterface::Execute_OnLoad(Actor, SaveGameInstance);
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Loading succeeded from slot: %s"), *SaveSlotName);
}

