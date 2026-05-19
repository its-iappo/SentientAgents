// Copyright Epic Games, Inc. All Rights Reserved.

#include "SentientAgentsCharacter.h"

#include "CharacterStats.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"

void ASentientAgentsCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (CharacterStats)
	{
		GetCharacterMovement()->JumpZVelocity = CharacterStats->JumpVelocity;
		GetCharacterMovement()->AirControl = CharacterStats->AirControl;
		GetCharacterMovement()->MaxWalkSpeed = CharacterStats->MaxWalkSpeed;
		GetCharacterMovement()->MinAnalogWalkSpeed = CharacterStats->MinAnalogWalkSpeed;
		GetCharacterMovement()->CrouchedSpeedMultiplier_DEPRECATED = CharacterStats->CrouchWalkSpeed;
	}
}

void ASentientAgentsCharacter::UpdateMovementSpeed()
{
}

ASentientAgentsCharacter::ASentientAgentsCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void ASentientAgentsCharacter::DoMove(float Right, float Forward)
{
	if (GetController() != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, Forward);
		AddMovementInput(RightDirection, Right);
	}
}

void ASentientAgentsCharacter::DoLook(float Yaw, float Pitch)
{
	if (GetController() != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void ASentientAgentsCharacter::DoJumpStart()
{
	// signal the character to jump
	Jump();
}

void ASentientAgentsCharacter::DoJumpEnd()
{
	// signal the character to stop jumping
	StopJumping();
}

void ASentientAgentsCharacter::ToggleRun()
{
	bIsRunning = !bIsRunning;

	if (bIsRunning && bIsCrouched)
	{
		UnCrouch();
	}
	UE_LOG(LogTemp, Display,TEXT("Run"));
	UpdateMovementSpeed();
}

void ASentientAgentsCharacter::ToggleCrouch()
{
	if (bIsCrouched)
	{
		UnCrouch();
	}
	else
	{
		Crouch();

		if (bIsRunning)
		{
			bIsRunning = false;
		}
	}
	UE_LOG(LogTemp, Display,TEXT("Crouch"));

	UpdateMovementSpeed();
}


void ASentientAgentsCharacter::Run()
{
}

void ASentientAgentsCharacter::Interact()
{
}

void ASentientAgentsCharacter::Use()
{
}

void ASentientAgentsCharacter::OpenInventory()
{
}

void ASentientAgentsCharacter::Attack()
{
}
