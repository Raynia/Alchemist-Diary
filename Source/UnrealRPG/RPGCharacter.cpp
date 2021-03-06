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

	DefaultHealthRestoredValue = static_cast<float>(MaxHealthPoint) / static_cast<float>(HEALTH_RESTORED_TIME);
	DefaultManaRestoreValue = static_cast<float>(MaxManaPoint) / static_cast<float>(MANA_RESTORED_TIME);
	DefaultStaminaReducedValue = static_cast<float>(MAX_STAMINA_POINT) / static_cast<float>(STAMINA_REDUCED_TIME);
	DefaultFoodReducedValue = static_cast<float>(MAX_FOOD_POINT) / static_cast<float>(FOOD_REDUCED_TIME);
	DefaultWaterReducedValue = static_cast<float>(MAX_WATER_POINT) / static_cast<float>(WATER_REDUCED_TIME);

	HealthRestoredValue = DefaultHealthRestoredValue;
	ManaRestoredValue = DefaultManaRestoreValue;
	StaminaReducedValue = DefaultStaminaReducedValue;
	FoodReducedValue = DefaultFoodReducedValue;
	WaterReducedValue = DefaultWaterReducedValue;	
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
	return DefaultHealthRestoredValue;
}

float ARPGCharacter::GetDefaultManaRestoredAmount()
{
	return DefaultManaRestoreValue;
}

float ARPGCharacter::GetDefaultStaminaDecreaseAmount()
{
	return DefaultStaminaReducedValue;
}

float ARPGCharacter::GetDefaultFoodDecreaseAmount()
{
	return DefaultFoodReducedValue;
}

float ARPGCharacter::GetDefaultWaterDecreaseAmount()
{
	return DefaultWaterReducedValue;
}

void ARPGCharacter::HealthRestore()
{
	HealthPoint += HealthRestoredValue * StatusVarianceTimeRate;
	if (FMath::TruncToInt(HealthPoint) > MaxHealthPoint)
	{
		HealthPoint = static_cast<float>(MaxHealthPoint);
	}
}

void ARPGCharacter::ManaRestore()
{
	ManaPoint += ManaRestoredValue * StatusVarianceTimeRate;
	if (FMath::TruncToInt(ManaPoint) > MaxManaPoint)
	{
		ManaPoint = static_cast<float>(MaxManaPoint);
	}
}

void ARPGCharacter::StaminaDecrease()
{
	StaminaPoint -= StaminaReducedValue * StatusVarianceTimeRate;
	if (FMath::CeilToInt(StaminaPoint) < MIN_STAMINA_POINT)
	{
		StaminaPoint = static_cast<float>(MIN_STAMINA_POINT);
	}
}

void ARPGCharacter::FoodDecrease()
{
	FoodPoint -= FoodReducedValue * StatusVarianceTimeRate;
	if (FMath::CeilToInt(FoodPoint) < MIN_FOOD_POINT)
	{
		FoodPoint = static_cast<float>(MIN_FOOD_POINT);
	}
}

void ARPGCharacter::WaterDecrease()
{
	WaterPoint -= WaterReducedValue * StatusVarianceTimeRate;
	if (FMath::CeilToInt(WaterPoint) < MIN_WATER_POINT)
	{
		WaterPoint = static_cast<float>(MIN_WATER_POINT);
	}	
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
