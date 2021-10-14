// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CodingTestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CODINGTEST_API ACodingTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
};
