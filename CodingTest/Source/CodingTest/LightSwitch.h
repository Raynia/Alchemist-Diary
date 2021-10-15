// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "LightSwitch.generated.h"

UCLASS()
class CODINGTEST_API ALightSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Switch Components")
	UPointLightComponent* PointLight1;

	UPROPERTY(VisibleAnywhere, Category = "Switch Components")
	USphereComponent* Sphere1;

	UFUNCTION()
	void OnOverlabBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlabEnd(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void ToggleLight();

	UPROPERTY(VisibleAnywhere, Category = "Switch Variables")
	float DesiredIntensity;
};
