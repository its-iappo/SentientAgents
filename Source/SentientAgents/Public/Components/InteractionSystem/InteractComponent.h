// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "InteractComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SENTIENTAGENTS_API UInteractComponent : public USphereComponent
{
	GENERATED_BODY()
	
	UPROPERTY()
	bool bIsOverlappingInteractable = false;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InteractionSphereRadius = 0.0f;

	UInteractComponent();

protected:

	virtual void BeginPlay() override;

public:

	UFUNCTION()
	void SpawnUI(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void DespawnUI(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
