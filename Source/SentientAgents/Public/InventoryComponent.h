// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemStruct.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventorySizeChangeSignature,UItemStruct*,Item);

UENUM()
enum class ESortMode : uint8
{
	ID UMETA(DisplayName = "By ID"),
	QUANTITY   UMETA(DisplayName = "By Quantity"),
	NAME      UMETA(DisplayName = "By Name")	
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SENTIENTAGENTS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	TArray<UItemStruct*> Inventory;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	FOnInventorySizeChangeSignature OnSizeChange; //when the size of the array changes
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	FOnInventorySizeChangeSignature OnStackChange; //when one of the items in the inventory has quantity increase or decrease

	
public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void AddItemToInventory(UItemStruct* Item);
	UFUNCTION(BlueprintCallable)
	UItemStruct* GetItemFromInventory(const int Index) const;
	UFUNCTION(BlueprintCallable)
	void RemoveItemFromInventory(const int Index);
	UFUNCTION(BlueprintCallable)
	void SortInventory(const ESortMode SortMode, const bool Ascending);
	UFUNCTION(BlueprintCallable)
	void SplitStack(const int Index,const int Size); //not implemented yet
};
