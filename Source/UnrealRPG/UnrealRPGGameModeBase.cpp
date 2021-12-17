// Copyright Epic Games, Inc. All Rights Reserved.


#include "UnrealRPGGameModeBase.h"

AUnrealRPGGameModeBase::AUnrealRPGGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;


}

void AUnrealRPGGameModeBase::StartPlay()
{
	Super::StartPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World!"));
	}	
}

void AUnrealRPGGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentTime += FMath::TruncToInt(DeltaTime * 1000);
	if (CurrentTime >= MAX_TIME)
	{
		CurrentTime = MIN_TIME;
	}
}

