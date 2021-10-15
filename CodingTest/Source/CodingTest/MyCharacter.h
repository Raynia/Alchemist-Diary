// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class CODINGTEST_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool isSprint;
	UCharacterMovementComponent* PlayerMovementComponent;
	float SprintWalkSpeed;
	float DefaultWalkSpeed;

	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void JumpStart();
	UFUNCTION()
	void JumpEnd();

	UFUNCTION()
	void SprintStart();
	UFUNCTION()
	void SprintEnd();

	UFUNCTION()
	void CrouchStart();
	UFUNCTION()
	void CrouchEnd();
};
