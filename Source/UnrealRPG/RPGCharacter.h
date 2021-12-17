// ⓒFox Tales Studio

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "RPGCharacter.generated.h"

UCLASS()
class UNREALRPG_API ARPGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/* Character Movement Setting */

	bool isSprint;
	float DefaultWalkSpeed;
	float SprintWalkSpeed;
	UCharacterMovementComponent* PlayerMovementComponent;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);
	UFUNCTION(BlueprintCallable)
	void StartJump();
	UFUNCTION(BlueprintCallable)
	void StopJump();
	UFUNCTION(BlueprintCallable)
	void StartSprint();
	UFUNCTION(BlueprintCallable)
	void StopSprint();
	UFUNCTION(BlueprintCallable)
	void Interact();

	/* Character Ability & State Setting */

	const int32 MIN_HEALTH_POINT = 0;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Max Value")
	int32 MaxHealthPoint = 2000;

	const int32 MIN_MANA_POINT = 0;
	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Max Value")
	int32 MaxManaPoint = 25000;

	const int32 MIN_STAMINA_POINT = -100;
	const int32 MAX_STAMINA_POINT = 1000;

	const int32 MIN_FOOD_POINT = 0;
	const int32 MAX_FOOD_POINT = 1000;

	const int32 MIN_WATER_POINT = 0;
	const int32 MAX_WATER_POINT = 1000;

	const int32 MAX_REST_TIME = 5;

	const float DEFAULT_HEALTH_RESTORED_AMOUNT = 5.0F;
	const float DEFAULT_MANA_RESTORED_AMOUNT = 140.0F;
	const float DEFAULT_STAMINA_DECREASED_AMOUNT = 0.31F;
	const float DEFAULT_FOOD_DECREASED_AMOUNT = 0.47F;
	const float DEFAULT_WATER_DECREASED_AMOUNT = 0.69F;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 1")
	float HealthPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 1")
	float ManaPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 1")
	float StaminaPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 1")
	float FoodPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 1")
	float WaterPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 2")
	float HealthRestoredAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 2")
	float ManaRestoredAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 2")
	float StaminaDecreasedAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 2")
	float FoodDecreasedAmount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Status 2")
	float WaterDecreasedAmount;

	uint16 RestCount;

	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void AwakeCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void WaitCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void SleepCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void RestCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void BlackOutCondition();

	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void HungerCondition();
	UFUNCTION(BlueprintCallable, Category = "Character Condition")
	void ThirstCondition();
	
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	int32 GetMinHealthPoint() const;
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	int32 GetMinManaPoint() const;
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	int32 GetMinStaminaPoint() const;
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	int32 GetMaxStaminaPoint() const;
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	int32 GetMinFoodPoint() const;
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	int32 GetMaxFoodPoint() const;
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	int32 GetMinWaterPoint() const;
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	int32 GetMaxWaterPoint() const;	

	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	float GetDefaultHealthRestoredAmount();
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	float GetDefaultManaRestoredAmount();
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	float GetDefaultStaminaDecreaseAmount();
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	float GetDefaultFoodDecreaseAmount();
	UFUNCTION(BlueprintPure, Category = "Character Constant Variable")
	float GetDefaultWaterDecreaseAmount();

	void HealthRestore();
	void ManaRestore();
	void StaminaDecrease();
	void FoodDecrease();
	void WaterDecrease();

	//음식과 수분 감소량의 보정치 계산
	float FoodAndWaterDecreasedAmountCalibration();

	/* Timer Setting */

	FTimerHandle HealthVarianceTimerHandle;
	FTimerHandle ManaVarianceTimerHandle;
	FTimerHandle StaminaDecreaseTimerHandle;
	FTimerHandle FoodDecreaseTimerHandle;
	FTimerHandle WaterDecreaseTimerHandle;

	float StatusVarianceTimeRate = 0.01f;

	void HealthVarianceTimer();
	void ManaVarianceTimer();
	void StaminaDecreaseTimer();
	void FoodaDecreaseTimer();
	void WaterDecreaseTimer();
};
