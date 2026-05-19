// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SENTIENTAGENTS_API IInteractable
{
	GENERATED_BODY()

public:
	
	//Communicate if the actor is effectively interactable, you can add in here any requirement to interact 
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool IsInteractable();
	
	//It is used to say how to interact 
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Interactable)
	void Interact();
};
