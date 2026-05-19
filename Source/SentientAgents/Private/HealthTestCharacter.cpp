// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthTestCharacter.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Controller.h"





AHealthTestCharacter::AHealthTestCharacter()
{
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

float AHealthTestCharacter::TakeDamage(float DamageAmount,FDamageEvent const& DamageEvent,
	AController* EventInstigator,AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	if (HealthComponent)
	{
		HealthComponent->TakeDamage(DamageAmount);
		HealthComponent->IsDeath.AddDynamic( this , &AHealthTestCharacter::HandleDeath );
	}
	

	return DamageAmount;
}

float AHealthTestCharacter::HealHealth(float healHealth)
{
	if (HealthComponent)
	{
		HealthComponent->HealHealth(healHealth);
	}
	return healHealth;
}
void AHealthTestCharacter::HandleDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("you are died"));
	
	GetCharacterMovement()->DisableMovement();
}







