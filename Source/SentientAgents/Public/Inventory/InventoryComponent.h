// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemStruct.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

UENUM()
enum class EInventoryInvalidActions : uint8
{
	SlotAlreadyUsed   UMETA(DisplayName = "Slot already used"),
	ItemNotEquippable  UMETA(DisplayName = "Item not equippable"),
	SlotAlreadyEmpty   UMETA(DisplayName = "Slot already empty"),
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventorySizeChangeSignature,FItemStruct,Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInvalidAction,EInventoryInvalidActions, Error);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemEquip,UItemDataAsset*, Item);

UENUM()
enum class ESortMode : uint8
{
	Quantity   UMETA(DisplayName = "By Quantity"),
	Name      UMETA(DisplayName = "By Name")	
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SENTIENTAGENTS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta=(AllowPrivateAccess))
	TArray<FItemStruct> Inventory;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	FOnInventorySizeChangeSignature OnSizeChange; //when the size of the array changes
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta=(AllowPrivateAccess))
	FOnInventorySizeChangeSignature OnStackChange; //when one of the items in the inventory has quantity increase or decrease
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta=(AllowPrivateAccess))
	TMap<EEquipmentSlot,FItemStruct> EquipmentSlots;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta=(AllowPrivateAccess))
	FOnInvalidAction OnInvalidAction;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta=(AllowPrivateAccess))
	FOnItemEquip OnItemEquip; //called when an item gets equipped
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta=(AllowPrivateAccess))
	FOnItemEquip OnItemUnequip; //called when an item gets unequipped
	
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
	void AddItemToInventory(UItemDataAsset* Item,int Quantity);
	UFUNCTION(BlueprintCallable)
	FItemStruct GetItemFromInventory(const int Index) const;
	UFUNCTION(BlueprintCallable)
	void RemoveItemFromInventoryByIndex(const int Index);
	UFUNCTION(BlueprintCallable)
	void RemoveItemFromInventoryByAsset(const UItemDataAsset* Item);
	UFUNCTION(BlueprintCallable) //removes an instance of an item in the inventory
	void SortInventory(const ESortMode SortMode, const bool Ascending);
	UFUNCTION()
	void SplitStack(const int Index,const int Size); //not implemented yet
	UFUNCTION(BlueprintCallable)
	void ReduceAmount(UItemDataAsset* Item,int Quantity);
	UFUNCTION(BlueprintCallable)
	void Equip(int Index);
	UFUNCTION(BlueprintCallable)
	void UnEquip(EEquipmentSlot Slot);
};
