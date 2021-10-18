// ⓒFox Tales Studio

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "DoubleLeafDoor.generated.h"

UCLASS()
class UNREALRPG_API ADoubleLeafDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoubleLeafDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float DoorRotateDegree = 90.f;
	enum DoorPosition
	{
		Left = 1,
		Right = -1,
	};

	UPROPERTY(VisibleAnywhere, Category = "Door Components")
	UStaticMeshComponent* DoorFrame;

	UPROPERTY(VisibleAnywhere, Category = "Door Components")
	UStaticMeshComponent* LeftDoor;
	UPROPERTY(VisibleAnywhere, Category = "Door Components")
	UStaticMeshComponent* RightDoor;

	UPROPERTY(VisibleAnywhere, Category = "Door Components")
	UArrowComponent* Arrow1;

	UPROPERTY(VisibleAnywhere, Category = "Switch Components")
	USphereComponent* Sphere1;

	UFUNCTION()
	void OnOverlabBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnOverlabEnd(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void DoorOpen(UStaticMeshComponent* TargetComponent, int DoorPosition);
	UFUNCTION()
	void DoorClose(UStaticMeshComponent* TargetComponent, int DoorPosition);
};
