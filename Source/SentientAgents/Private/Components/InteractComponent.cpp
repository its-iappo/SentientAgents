// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Components/InteractComponent.h"

#include "Interfaces/Interactable.h"


UInteractComponent::UInteractComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	
	SetSphereRadius(InteractionSphereRadius);
	//SetCollisionResponseToAllChannels(ECR_Ignore);
	//SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SetGenerateOverlapEvents(true);
	
	OnComponentBeginOverlap.AddDynamic(this, &UInteractComponent::SpawnUI);
	OnComponentEndOverlap.AddDynamic(this, &UInteractComponent::DespawnUI);
}

void UInteractComponent::SpawnUI(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UI spawn logic on single actor 
	
	if (OtherActor->Implements<UInteractable>())
	{
		
		
		
	}
	
}

void UInteractComponent::DespawnUI(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//UI despawn logic
}

