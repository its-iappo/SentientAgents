// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "SentientAgentsCharacter.h"
#include "HealthComponent.h"
#include "HealthTestCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class UHealthComponent;
struct FInputActionValue;

UCLASS()
class SENTIENTAGENTS_API AHealthTestCharacter : public ASentientAgentsCharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;
	
public:
	AHealthTestCharacter(); 
	
	UFUNCTION(BlueprintCallable)
	virtual float TakeDamage(float DamageAmount,FDamageEvent const& DamageEvent,
		AController* EventInstigator,AActor* DamageCauser) override;
	
	void HealHealth(float healHealth);
	
protected:
	UFUNCTION()
	void HandleDeath();
	
	
	
};
