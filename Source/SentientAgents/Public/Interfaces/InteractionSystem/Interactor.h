// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactor.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SENTIENTAGENTS_API IInteractor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	class UInteractComponent* GetInteractComponent();

	//It is used to implement the interact action 
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interaction();
};
