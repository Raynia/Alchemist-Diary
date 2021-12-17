// ⓒFox Tales Studio


#include "RPGCharacter.h"

// Sets default values
ARPGCharacter::ARPGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	isSprint = false;
	PlayerMovementComponent = GetCharacterMovement();
	DefaultWalkSpeed = PlayerMovementComponent->MaxWalkSpeed;
	SprintWalkSpeed = DefaultWalkSpeed * 2.0f;
	
	HealthPoint = MaxHealthPoint;
	ManaPoint = MaxManaPoint;
	StaminaPoint = MAX_STAMINA_POINT;
	FoodPoint = MAX_FOOD_POINT;
	WaterPoint = MAX_WATER_POINT;

	HealthRestoredAmount = DEFAULT_HEALTH_RESTORED_AMOUNT;
	ManaRestoredAmount = DEFAULT_MANA_RESTORED_AMOUNT;
	StaminaDecreasedAmount = DEFAULT_STAMINA_DECREASED_AMOUNT;
	FoodDecreasedAmount = DEFAULT_FOOD_DECREASED_AMOUNT;
	WaterDecreasedAmount = DEFAULT_WATER_DECREASED_AMOUNT;	
}

// Called when the game starts or when spawned
void ARPGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(HealthVarianceTimerHandle, this, &ARPGCharacter::HealthRestore, StatusVarianceTimeRate, true);
	GetWorldTimerManager().SetTimer(ManaVarianceTimerHandle, this, &ARPGCharacter::ManaRestore, StatusVarianceTimeRate, true);
	GetWorldTimerManager().SetTimer(StaminaDecreaseTimerHandle, this, &ARPGCharacter::StaminaDecrease, StatusVarianceTimeRate, true);
	GetWorldTimerManager().SetTimer(FoodDecreaseTimerHandle, this, &ARPGCharacter::FoodDecrease, StatusVarianceTimeRate, true);
	GetWorldTimerManager().SetTimer(WaterDecreaseTimerHandle, this, &ARPGCharacter::WaterDecrease, StatusVarianceTimeRate, true);	
}

// Called every frame
void ARPGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ARPGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ARPGCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARPGCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &ARPGCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ARPGCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ARPGCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ARPGCharacter::StopJump);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ARPGCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ARPGCharacter::StopSprint);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ARPGCharacter::Interact);
	
}

void ARPGCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);

}

void ARPGCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ARPGCharacter::StartJump()
{
	bPressedJump = true;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("Jump!"));
	}	
}

void ARPGCharacter::StopJump()
{
	bPressedJump = false;
}

void ARPGCharacter::StartSprint()
{
	isSprint = true;
	PlayerMovementComponent->MaxWalkSpeed = SprintWalkSpeed;
}

void ARPGCharacter::StopSprint()
{
	isSprint = false;
	PlayerMovementComponent->MaxWalkSpeed = DefaultWalkSpeed;
}

void ARPGCharacter::Interact()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("E pressed"));
	}
}

void ARPGCharacter::AwakeCondition()
{

}

void ARPGCharacter::WaitCondition()
{

}

void ARPGCharacter::RestCondition()
{

}

void ARPGCharacter::SleepCondition()
{

}

void ARPGCharacter::BlackOutCondition()
{

}

void ARPGCharacter::HungerCondition()
{

}

void ARPGCharacter::ThirstCondition()
{

}

int32 ARPGCharacter::GetMinHealthPoint() const
{
	return MIN_HEALTH_POINT;
}

int32 ARPGCharacter::GetMinManaPoint() const
{
	return MIN_MANA_POINT;
}

int32 ARPGCharacter::GetMinStaminaPoint() const
{
	return MIN_STAMINA_POINT;
}

int32 ARPGCharacter::GetMaxStaminaPoint() const
{
	return MAX_STAMINA_POINT;
}

int32 ARPGCharacter::GetMinFoodPoint() const
{
	return MIN_FOOD_POINT;
}

int32 ARPGCharacter::GetMaxFoodPoint() const
{
	return MAX_FOOD_POINT;
}

int32 ARPGCharacter::GetMinWaterPoint() const
{
	return MIN_WATER_POINT;
}

int32 ARPGCharacter::GetMaxWaterPoint() const
{
	return MAX_WATER_POINT;
}

float ARPGCharacter::GetDefaultHealthRestoredAmount()
{
	return DEFAULT_HEALTH_RESTORED_AMOUNT;
}

float ARPGCharacter::GetDefaultManaRestoredAmount()
{
	return DEFAULT_MANA_RESTORED_AMOUNT;
}

float ARPGCharacter::GetDefaultStaminaDecreaseAmount()
{
	return DEFAULT_STAMINA_DECREASED_AMOUNT;
}

float ARPGCharacter::GetDefaultFoodDecreaseAmount()
{
	return DEFAULT_FOOD_DECREASED_AMOUNT;
}

float ARPGCharacter::GetDefaultWaterDecreaseAmount()
{
	return DEFAULT_WATER_DECREASED_AMOUNT;
}

void ARPGCharacter::HealthRestore()
{
	HealthPoint += HealthRestoredAmount * StatusVarianceTimeRate;
	if (FMath::TruncToInt(HealthPoint) > MaxHealthPoint)
	{
		HealthPoint = static_cast<float>(MaxHealthPoint);
	}
}

void ARPGCharacter::ManaRestore()
{
	ManaPoint += ManaRestoredAmount * StatusVarianceTimeRate;
	if (FMath::TruncToInt(ManaPoint) > MaxManaPoint)
	{
		ManaPoint = static_cast<float>(MaxManaPoint);
	}
}

void ARPGCharacter::StaminaDecrease()
{
	StaminaPoint -= StaminaDecreasedAmount * StatusVarianceTimeRate;
	if (FMath::CeilToInt(StaminaPoint) < MIN_STAMINA_POINT)
	{
		StaminaPoint = static_cast<float>(MIN_STAMINA_POINT);
	}
}

void ARPGCharacter::FoodDecrease()
{
	FoodDecreasedAmount = (DEFAULT_FOOD_DECREASED_AMOUNT + FoodAndWaterDecreasedAmountCalibration()) * StatusVarianceTimeRate;
	FoodPoint -= FoodDecreasedAmount;
	if (FMath::CeilToInt(FoodPoint) < MIN_FOOD_POINT)
	{
		FoodPoint = static_cast<float>(MIN_FOOD_POINT);
	}
}

void ARPGCharacter::WaterDecrease()
{
	WaterDecreasedAmount = (DEFAULT_WATER_DECREASED_AMOUNT + FoodAndWaterDecreasedAmountCalibration()) * StatusVarianceTimeRate;
	WaterPoint -= WaterDecreasedAmount;
	if (FMath::CeilToInt(WaterPoint) < MIN_WATER_POINT)
	{
		WaterPoint = MIN_WATER_POINT;
	}	
}

float ARPGCharacter::FoodAndWaterDecreasedAmountCalibration()
{
	return FMath::Abs((HealthPoint / static_cast<float>(MaxHealthPoint)) - 1.0f) * 0.25f;
}

void ARPGCharacter::HealthVarianceTimer()
{
}

void ARPGCharacter::ManaVarianceTimer()
{
}

void ARPGCharacter::StaminaDecreaseTimer()
{
}

void ARPGCharacter::FoodaDecreaseTimer()
{
}

void ARPGCharacter::WaterDecreaseTimer()
{
}
