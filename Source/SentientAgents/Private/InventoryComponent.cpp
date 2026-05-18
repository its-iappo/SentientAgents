// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

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

void UInventoryComponent::AddItemToInventory(UItemStruct* Item)
{
	if (Item->bIsStackable) 
	{
		for (const auto Element : Inventory)
		{
			if (Element->ID == Item->ID) //if it's the same item it stacks
			{
				Element->Quantity += Item->Quantity;
				OnStackChange.Broadcast(Element);
				break;
			}
		}
	}
	else
	{
		OnSizeChange.Broadcast(Item);
		Inventory.Add(Item);
	}
}

UItemStruct* UInventoryComponent::GetItemFromInventory(const int Index) const
{
	if (Index < Inventory.Num())
	{
		return Inventory[Index];
	}
	return nullptr;
}

void UInventoryComponent::RemoveItemFromInventory(const int Index)
{
	if (Index < Inventory.Num())
	{
		OnSizeChange.Broadcast(Inventory[Index]);
		Inventory.RemoveAtSwap(Index);
	}
}

void UInventoryComponent::SortInventory(const ESortMode SortMode, const bool Ascending)
{
	//man this code could be a lot better ¯\_(ツ)_/¯
	switch (SortMode)
	{
	case ESortMode::ID: //sorting by id
		for (int i = 0; i < Inventory.Num(); i++) //i know it's not the most efficient algorithm
		{
			for (int j = i+1; j < Inventory.Num(); j++)
			{
				if (Ascending)
				{
					if (Inventory[i]->ID > Inventory[j]->ID)
					{
						UItemStruct* temp = Inventory[i];
						Inventory[i] = Inventory[j];
						Inventory[j] = temp;
					}
				}
				else
				{
					if (Inventory[i]->ID < Inventory[j]->ID)
					{
						UItemStruct* temp = Inventory[i];
						Inventory[i] = Inventory[j];
						Inventory[j] = temp;
					}
				}
			}
		}
		break;
	case ESortMode::QUANTITY:
		for (int i = 0; i < Inventory.Num(); i++)
		{
			for (int j = i+1; j < Inventory.Num(); j++)
			{
				if (Ascending)
				{
					if (Inventory[i]->Quantity > Inventory[j]->Quantity)
					{
						UItemStruct* temp = Inventory[i];
						Inventory[i] = Inventory[j];
						Inventory[j] = temp;
					}
				}
				else
				{
					if (Inventory[i]->Quantity < Inventory[j]->Quantity)
					{
						UItemStruct* temp = Inventory[i];
						Inventory[i] = Inventory[j];
						Inventory[j] = temp;
					}
				}
			}
		}
		break;
	case ESortMode::NAME:
		for (int i = 0; i < Inventory.Num(); i++)
		{
			for (int j = i+1; j < Inventory.Num(); j++)
			{
				if (Ascending)
				{
					if (Inventory[i]->Name > Inventory[j]->Name)
					{
						UItemStruct* temp = Inventory[i];
						Inventory[i] = Inventory[j];
						Inventory[j] = temp;
					}
				}
				else
				{
					if (Inventory[i]->Name < Inventory[j]->Name)
					{
						UItemStruct* temp = Inventory[i];
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
		if (Inventory[Index]->bIsStackable)
		{
			if (Size < Inventory[Index]->Quantity)
			{
				//i'll think about it later
			}
		}
	}
}
		

