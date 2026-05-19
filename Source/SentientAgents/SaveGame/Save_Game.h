// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Save_Game.generated.h"

USTRUCT(BlueprintType)
struct FPlayerSaveData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	FTransform PlayerTransform;

	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	float PlayerHealth = 100.0f;
};

USTRUCT(BlueprintType)
struct FActorSaveData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	FName ActorName;

	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	FTransform ActorTransform;

	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	bool bIsActive = true;
};

UCLASS()
class SENTIENTAGENTS_API USave_Game : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	FPlayerSaveData PlayerData;

	UPROPERTY(BlueprintReadWrite, Category = "SaveData")
	TArray<FActorSaveData> SavedActors;
};
