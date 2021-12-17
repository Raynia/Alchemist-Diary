// ⓒFox Tales Studio

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TimeFunction.generated.h"

/**
 * 
 */
UCLASS()
class UNREALRPG_API UTimeFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static FORCEINLINE float MillisecondsToSeconds(int32 Milliseconds)
	{
		return static_cast<float>(Milliseconds) / 1000.0f;
	}

	static FORCEINLINE int32 SecondsToMilliseconds(float Seconds)
	{
		return static_cast<int32>(Seconds * 1000.0f);
	}

};
