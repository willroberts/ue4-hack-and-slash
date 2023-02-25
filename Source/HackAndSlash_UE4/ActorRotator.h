// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ActorRotator.generated.h"

/**
 * 
 */
UCLASS()
class HACKANDSLASH_UE4_API UActorRotator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FRotator InterpolatePlayerRotation(float fInterpSpeed);
};
