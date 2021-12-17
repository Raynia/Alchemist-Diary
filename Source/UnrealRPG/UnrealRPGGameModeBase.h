// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealRPGGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UNREALRPG_API AUnrealRPGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealRPGGameModeBase();

protected:
	virtual void StartPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	int32 CurrentTime;
	const int32 MIN_TIME = 0;
	const int32 MAX_TIME = 4320000;
};
