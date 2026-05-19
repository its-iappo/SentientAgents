// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "HealthTestCharacter.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

// METTERE DANNO A SHIELD
void UHealthComponent::TakeDamage(float damage)
{
	if (CurrentHealth <= 0)
	{
		//CharacterDie();
		
	}
	else if(CurrentHealth > 0){
		CurrentHealth -= damage;
		
	}
};

void UHealthComponent::HealHealth(float healHealth)
{
	if (CurrentHealth > 0)
	{
		CurrentHealth += healHealth;
	}
}

void UHealthComponent::HealShield(float healShield)
{
	if (CurrentShield > 0)
	{
		CurrentShield += healShield;
	}
}

