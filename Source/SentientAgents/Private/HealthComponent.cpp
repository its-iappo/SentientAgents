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
	if (CurrentHealth <= 0.0f)
	{
		
		IsDeath.Broadcast();
		
	}
	else if(CurrentHealth > 0.0f){
		CurrentHealth -= damage;
		
		CurrentHealth = FMath::Clamp(CurrentHealth - damage,0.0f,MaxHealth);
		
	}
};

void UHealthComponent::HealHealth(float healHealth)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + healHealth, 0.0f, 100.0f);
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("CurrentHealth: %f"), CurrentHealth));
}


void UHealthComponent::HealShield(float healShield)
{
	CurrentShield = FMath::Clamp(CurrentShield + healShield, 0.0f, 100.0f);
	
	GEngine->AddOnScreenDebugMessage(-1, 0.75f, FColor::Green, FString::Printf(TEXT("CurrentShield: %f"), CurrentShield));
}

