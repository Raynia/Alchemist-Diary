// Copyright Epic Games, Inc. All Rights Reserved.


#include "UnrealRPGGameModeBase.h"

void AUnrealRPGGameModeBase::StartPlay()
{
	Super::StartPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World!"));
	}
}