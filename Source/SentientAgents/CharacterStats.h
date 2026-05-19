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
	float MaxWalkSpeed = 500.0f; 
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=" Movement ")
	float MinAnalogWalkSpeed = 20.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=" Movement ")
	float CrouchWalkSpeed= 300.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=" Movement ")
	float JumpVelocity = 500.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=" Movement ")
	float AirControl = 0.35f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Interaction")
	float InteractionRadius = 100.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Statistics")
	float MaxHealth = 100.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Statistics")
	float Armor = 25.0f;
};
