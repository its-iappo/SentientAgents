// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterStats.generated.h"


UCLASS()
class SENTIENTAGENTS_API UCharacterStats : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=" Movement ")
	float WalkSpeed = 500.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=" Movement ")
	float CrouchWalkSpeed= 300.0f;
};
