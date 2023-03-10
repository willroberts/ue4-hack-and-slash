// © 2023 Will Roberts

#include "RotationInterpolator.h"
#include "GameFramework/Controller.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

// This function runs in the event tick (on every frame) to interpolate the pawn's rotation while animations are playing.
bool URotationInterpolator::InterpolatePlayerRotation(float InterpSpeed) {
	UWorld* WorldRef = GEngine->GameViewport->GetWorld();
	if (!WorldRef)
	{
		return false;
	}

	APlayerController* ControllerRef = UGameplayStatics::GetPlayerController(WorldRef, 0);
	if (!ControllerRef)
	{
		return false;
	}

	APawn* PawnRef = ControllerRef->GetPawn();
	if (!PawnRef)
	{
		return false;
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
		UKismetMathLibrary::ComposeRotators(
			CurrentInputRotation,
			ControllerRef->GetControlRotation()
		).Yaw // Yaw
	);

	// Interpolate the rotation and rotate the player.
	FRotator Interpolated = FMath::RInterpTo(PawnRef->GetActorRotation(), YawRotator, UGameplayStatics::GetWorldDeltaSeconds(WorldRef), InterpSpeed);
	return PawnRef->SetActorRotation(Interpolated, ETeleportType::None);
}