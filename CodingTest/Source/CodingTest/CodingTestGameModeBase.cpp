// Copyright Epic Games, Inc. All Rights Reserved.


#include "CodingTestGameModeBase.h"

void ACodingTestGameModeBase::StartPlay()
{
	Super::StartPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World!"));
	}
}
