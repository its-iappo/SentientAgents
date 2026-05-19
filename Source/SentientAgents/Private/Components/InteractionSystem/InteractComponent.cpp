// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Components/InteractionSystem/InteractComponent.h"
#include "Interfaces/InteractionSystem/Interactable.h"


UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	
	//SetCollisionResponseToAllChannels(ECR_Ignore);
	//SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	OnComponentBeginOverlap.AddDynamic(this, &UInteractComponent::SpawnUI);
	OnComponentEndOverlap.AddDynamic(this, &UInteractComponent::DespawnUI);
	
	SetSphereRadius(InteractionSphereRadius);
	SetGenerateOverlapEvents(true);
}

void UInteractComponent::SpawnUI(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UI spawn logic on single actor 
	
	if (OtherActor->Implements<UInteractable>())
	{
		bIsOverlappingInteractable = true;	
	}
	
}

void UInteractComponent::DespawnUI(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//UI despawn logic
	
	if (!OtherActor)
	{
		bIsOverlappingInteractable = false;
	}
}

