// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Class.h"
#include "ItemStruct.generated.h"

/**
 Quick explanation:
 Any stat that is set to -1 will have no effect and will be hidden 
 */
UCLASS()
class SENTIENTAGENTS_API UItemStruct : public UStruct
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	int ID = 0;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	int Quantity = 1;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	FString Name = "";
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	UTexture2D* Icon;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	bool bIsStackable = false;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	float Damage = 0;
};
