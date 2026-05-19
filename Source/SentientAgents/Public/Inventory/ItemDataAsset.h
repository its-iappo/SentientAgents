// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDataAsset.generated.h"

/**
 * 
 */
UENUM()
enum class EEquipmentSlot : uint8
{
	None UMETA(DisplayName="None"),
	Weapon   UMETA(DisplayName = "Weapon"),
	Head   UMETA(DisplayName = "Head"),
	Chest   UMETA(DisplayName = "Chest"),
	Leggings   UMETA(DisplayName = "Leggings"),
	Boots UMETA(DisplayName = "Boots")
};

UCLASS()
class SENTIENTAGENTS_API UItemDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	FString Name = "";
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	UTexture2D* Icon;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	bool bIsStackable = false;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	float Damage = 0;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	float Defense = 0;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	EEquipmentSlot Slot = EEquipmentSlot::None;
};
