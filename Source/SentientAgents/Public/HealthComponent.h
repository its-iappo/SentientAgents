// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FonDeathDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float, NewHealth);


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SENTIENTAGENTS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHealthComponent();
	
	UPROPERTY(BlueprintAssignable, Category = "Character State")
	FonDeathDelegate IsDeath;
	
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Component")
	float MaxHealth = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Component")
	float CurrentHealth = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Component")
	float MaxShield = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Component")
	float CurrentShield = 100.0f;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	void TakeDamage(float damage);
	
	UFUNCTION(BlueprintCallable)
	void HealHealth(float healHealth);
	void HealShield(float healShield);
};
