// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ISavableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UISavableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SENTIENTAGENTS_API IISavableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	
public:
	
	// Event made to save the actor's state in the object Savegame
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "SaveSystem")
	void OnSave(class USave_Game* SaveGame);

	// Event made to load the actor's state in the object Savegame
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "SaveSystem")
	void OnLoad(class USave_Game* SaveGame);
};


