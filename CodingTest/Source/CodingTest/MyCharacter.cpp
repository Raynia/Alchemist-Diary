// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter() : SprintWalkSpeed(1000.f)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isSprint = false;
	PlayerMovementComponent = GetCharacterMovement();
	DefaultWalkSpeed = PlayerMovementComponent->MaxWalkSpeed;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	AutoReceiveInput = EAutoReceiveInput::Player0;	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::JumpStart);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::JumpEnd);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyCharacter::SprintStart);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyCharacter::SprintEnd);

	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMyCharacter::CrouchStart);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AMyCharacter::CrouchEnd);
}

void AMyCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AMyCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}


void AMyCharacter::JumpStart()
{
	bPressedJump = true;
}

void AMyCharacter::JumpEnd()
{
	bPressedJump = false;
}

void AMyCharacter::SprintStart()
{
	isSprint = true;
	PlayerMovementComponent->MaxWalkSpeed = SprintWalkSpeed;
}

void AMyCharacter::SprintEnd()
{
	isSprint = false;
	PlayerMovementComponent->MaxWalkSpeed = DefaultWalkSpeed;
}

void AMyCharacter::CrouchStart()
{
	
}

void AMyCharacter::CrouchEnd()
{

}

