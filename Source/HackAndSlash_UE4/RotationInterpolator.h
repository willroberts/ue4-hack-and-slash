// © 2023 Will Roberts

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RotationInterpolator.generated.h"

/**
 * 
 */
UCLASS()
class HACKANDSLASH_UE4_API URotationInterpolator : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool InterpolatePlayerRotation(float InterpSpeed = 5.0);
};
