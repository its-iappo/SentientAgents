// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemDataAsset.h"
#include "UObject/Class.h"
#include "ItemStruct.generated.h"

/**
 Quick explanation:
 Any stat that is set to -1 will have no effect and will be hidden 
 */
USTRUCT(BlueprintType)
struct SENTIENTAGENTS_API FItemStruct
{
	GENERATED_BODY()

public:
	FItemStruct()
	{
		ItemDataAsset = nullptr;
		Quantity = 0;
	}
	
	FItemStruct(UItemDataAsset* Item, const int Quantity)
	{
		ItemDataAsset = Item;
		this->Quantity = Quantity;
	}
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta=(AllowPrivateAccess))
	UItemDataAsset* ItemDataAsset;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta=(AllowPrivateAccess))
	int Quantity = 1;
};
