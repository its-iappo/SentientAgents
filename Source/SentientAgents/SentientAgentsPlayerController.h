// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SentientAgentsPlayerController.generated.h"

struct FInputActionValue;
class ASentientAgentsCharacter;
class UInputAction;
class UInputMappingContext;
class UUserWidget;

/**
 *  Basic PlayerController class for a third person game
 *  Manages input mappings
 */
UCLASS(abstract)
class ASentientAgentsPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* InteractAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* CrouchAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* RunAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* OpenInventoryAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* UseAction;
	
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* AttackAction;
	
	
	/** ControlledCharacter **/
	UPROPERTY()
	TObjectPtr<ASentientAgentsCharacter> ControlledCharacter;
	
	UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;
	
	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;
	
	virtual void OnPossess(APawn* InPawn)override;
	
public:
	
	UFUNCTION()
	void Jump();
	
	UFUNCTION()
	void StopJumping();
	
	UFUNCTION()
	void Look(const FInputActionValue& Value);
	
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	
	UFUNCTION()
	virtual void Interact();
	
	UFUNCTION()
	virtual void Crouch();
	
	UFUNCTION()
	virtual void Run();
	
	UFUNCTION()
	virtual void OpenInventory();
	
	UFUNCTION()
	virtual void Use();
	
	UFUNCTION()
	virtual void Attack();
	
};
