// Copyright Epic Games, Inc. All Rights Reserved.


#include "SentientAgentsPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "SentientAgents.h"
#include "SentientAgentsCharacter.h"


void ASentientAgentsPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ASentientAgentsPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this,
		                                   &ASentientAgentsPlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this,
		                                   &ASentientAgentsPlayerController::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this,
		                                   &ASentientAgentsPlayerController::Move);
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this,
		                                   &ASentientAgentsPlayerController::Look);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this,
		                                   &ASentientAgentsPlayerController::Look);

		// Interact
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this,
		                                   &ASentientAgentsPlayerController::Interact);

		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this,
		                                   &ASentientAgentsPlayerController::Crouch);

		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this,
		                                   &ASentientAgentsPlayerController::Run);

		EnhancedInputComponent->BindAction(OpenInventoryAction, ETriggerEvent::Triggered, this,
		                                   &ASentientAgentsPlayerController::OpenInventory);

		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this,
		                                   &ASentientAgentsPlayerController::Attack);
		
		EnhancedInputComponent->BindAction(UseAction, ETriggerEvent::Triggered, this,
		                                   &ASentientAgentsPlayerController::Use);
	}
	else
	{
		UE_LOG(LogSentientAgents, Error,
		       TEXT(
			       "'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."
		       ), *GetNameSafe(this));
	}
}

void ASentientAgentsPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	ControlledCharacter = CastChecked<ASentientAgentsCharacter>(InPawn);
	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = GetLocalPlayer()->GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>())
	{
		InputSubsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void ASentientAgentsPlayerController::Jump()
{
	if (ControlledCharacter)
	{
		ControlledCharacter->Jump();
	}
}

void ASentientAgentsPlayerController::StopJumping()
{
	if (ControlledCharacter)
	{
		ControlledCharacter->StopJumping();
	}
}

void ASentientAgentsPlayerController::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	// route the input
	ControlledCharacter->DoLook(LookAxisVector.X, LookAxisVector.Y);
}

void ASentientAgentsPlayerController::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	// route the input
	ControlledCharacter->DoMove(MovementVector.X, MovementVector.Y);
}

void ASentientAgentsPlayerController::Interact()
{
	if (ControlledCharacter)
	{
		ControlledCharacter->Interact();
	}
}

void ASentientAgentsPlayerController::Crouch()
{
	if (ControlledCharacter)
	{
		ControlledCharacter->ToggleCrouch();
	}
}

void ASentientAgentsPlayerController::Run()
{
	if (ControlledCharacter)
	{
		ControlledCharacter->ToggleRun();
	}
}

void ASentientAgentsPlayerController::OpenInventory()
{
	if (ControlledCharacter)
	{
		ControlledCharacter->OpenInventory();
	}
}

void ASentientAgentsPlayerController::Use()
{
	if (ControlledCharacter)
	{
		ControlledCharacter->Use();
	}
}

void ASentientAgentsPlayerController::Attack()
{
	if (ControlledCharacter)
	{
		ControlledCharacter->Attack();
	}
}
