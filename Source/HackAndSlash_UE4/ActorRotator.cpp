// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorRotator.h"
#include "GameFramework/Controller.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

// This function runs in the event tick (on every frame) to interpolate the pawn's rotation for smooth camera movement.
FRotator UActorRotator::InterpolatePlayerRotation(
	float fInterpSpeed = 5.0
) {
	UWorld* WorldRef = GetWorld();
	if (!WorldRef);
	{
		return;
	}

	APlayerController* ControllerRef = UGameplayStatics::GetPlayerController(WorldRef, 0);
	if (!ControllerRef)
	{
		return;
	}

	APawn* PawnRef = ControllerRef->GetPawn();
	if (!PawnRef)
	{
		return;
	}

	// Get the current input rotation from the controller.
	float AxisValueX = ControllerRef->GetInputAxisValue(FName("MoveForward"));
	float AxisValueY = ControllerRef->GetInputAxisValue(FName("MoveRight"));
	FRotator CurrentInputRotation = UKismetMathLibrary::MakeRotationFromAxes(
		UKismetMathLibrary::MakeVector(AxisValueX, AxisValueY, 0.0), // Forward
		FVector::ZeroVector, // Right
		FVector::ZeroVector // Up
	);

	// Apply the player's current aim rotation to the input rotation, and save the resulting Yaw.
	FRotator YawRotator = UKismetMathLibrary::MakeRotator(
		0.0, // Roll
		0.0, // Pitch
		UKismetMathLibrary::ComposeRotators(CurrentInputRotation, ControllerRef->GetControlRotation()).Vector().Z // Yaw
	);

	// Interpolate and return the rotation.
	return FMath::RInterpTo(PawnRef->GetActorRotation(), YawRotator, UGameplayStatics::GetWorldDeltaSeconds(WorldRef), fInterpSpeed);
}
