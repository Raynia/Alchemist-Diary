// ⓒFox Tales Studio, All rights reserved


#include "RPGCharacter.h"

// Sets default values
ARPGCharacter::ARPGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	isSprint = false;
	PlayerMovementComponent = GetCharacterMovement();
	DefaultWalkSpeed = PlayerMovementComponent->MaxWalkSpeed;
	SprintWalkSpeed = DefaultWalkSpeed * 2.0f;
}

// Called when the game starts or when spawned
void ARPGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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
		GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("F pressed"));
	}
}
