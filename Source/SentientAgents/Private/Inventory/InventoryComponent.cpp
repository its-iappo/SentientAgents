// Fill out your copyright notice in the Description page of Project Settings.



#include "Inventory/InventoryComponent.h"

#include "IDetailTreeNode.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::AddItemToInventory(UItemDataAsset* Item, int Quantity)
{
	if (Item->bIsStackable)
	{
		bool Found = false;
		for (int i = 0 ; i < Inventory.Num() && !Found; i++)
		{
			if (Inventory[i].ItemDataAsset == Item) //if it's the same item it stacks
			{
				Inventory[i].Quantity += Quantity;
				OnStackChange.Broadcast(Inventory[i]);
				UE_LOG(LogTemp,Log,TEXT("Stacked"));
				Found = true;
			}
		}
		if (!Found)
		{
			Inventory.Add(FItemStruct(Item,Quantity));
		}
	}
	else
	{
		FItemStruct temp;
		temp.ItemDataAsset = Item;
		temp.Quantity = Quantity;
		OnSizeChange.Broadcast(temp);
		Inventory.Add(temp);
	}
}

FItemStruct UInventoryComponent::GetItemFromInventory(const int Index) const
{
	if (Index < Inventory.Num())
	{
		return Inventory[Index];
	}
	return FItemStruct();
}

void UInventoryComponent::RemoveItemFromInventoryByIndex(const int Index)
{
	if (Index < Inventory.Num())
	{
		OnSizeChange.Broadcast(Inventory[Index]);
		Inventory.RemoveAt(Index);
	}
}

void UInventoryComponent::RemoveItemFromInventoryByAsset(const UItemDataAsset* Item)
{
	for (int i = 0 ; i < Inventory.Num();i++)
	{
		if (Inventory[i].ItemDataAsset == Item)
		{
			Inventory.RemoveAt(i);
			return;
		}
	}
}

void UInventoryComponent::SortInventory(const ESortMode SortMode, const bool Ascending)
{
	//man this code could be a lot better ¯\_(ツ)_/¯
	switch (SortMode)
	{
	case ESortMode::Quantity:
		for (int i = 0; i < Inventory.Num(); i++) //i know it's not the most efficient algorithm
		{
			for (int j = i+1; j < Inventory.Num(); j++)
			{
				if (Ascending)
				{
					if (Inventory[i].Quantity > Inventory[j].Quantity)
					{
						FItemStruct temp = Inventory[i];
						Inventory[i] = Inventory[j];
						Inventory[j] = temp;
					}
				}
				else
				{
					if (Inventory[i].Quantity < Inventory[j].Quantity)
					{
						FItemStruct temp = Inventory[i];
						Inventory[i] = Inventory[j];
						Inventory[j] = temp;
					}
				}
			}
		}
		break;
	case ESortMode::Name:
		for (int i = 0; i < Inventory.Num(); i++)
		{
			for (int j = i+1; j < Inventory.Num(); j++)
			{
				if (Ascending)
				{
					if (Inventory[i].ItemDataAsset->Name > Inventory[j].ItemDataAsset->Name)
					{
						FItemStruct temp = Inventory[i];
						Inventory[i] = Inventory[j];
						Inventory[j] = temp;
					}
				}
				else
				{
					if (Inventory[i].ItemDataAsset->Name < Inventory[j].ItemDataAsset->Name)
					{
						FItemStruct temp = Inventory[i];
						Inventory[i] = Inventory[j];
						Inventory[j] = temp;
					}
				}
			}
		}
		break;
	}
}

void UInventoryComponent::SplitStack(const int Index,const int Size)
{
	if (Index < Inventory.Num())
	{
		if (Inventory[Index].ItemDataAsset->bIsStackable)
		{
			if (Size < Inventory[Index].Quantity)
			{
				//i'll think about it later
			}
		}
	}
}

void UInventoryComponent::ReduceAmount(UItemDataAsset* Item, int Quantity)//reduce the quantity in a stackable item
{
	if (Quantity < 1)
	{
		UE_LOG(LogTemp,Warning,TEXT("Quantity was set to a negative number"));
		return;
	}
	if (Item->bIsStackable)
	{
		bool Found = false;
		for (int i = 0 ; i < Inventory.Num() && !Found; i++)
		{
			if (Inventory[i].ItemDataAsset == Item)
			{
				if (Inventory[i].Quantity > Quantity)
				{
					Inventory[i].Quantity -= Quantity;
					OnStackChange.Broadcast(Inventory[i]);
				}
				else
				{
					UE_LOG(LogTemp,Warning,TEXT("Attempted to reduce the quantity to a negative amount!"));
				}
			}
		}
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Attempted to reduce the quantity of an unstackable item!"));
	}
}
