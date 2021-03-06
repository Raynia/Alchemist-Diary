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

	bool IsDoorOpened;

	UPROPERTY(VisibleAnyWhere)
	float OriginLeftDoorDegree;
	UPROPERTY(VisibleAnyWhere)
	float OriginRightDoorDegree;

	UPROPERTY(VisibleAnywhere, Category = "Door Components")
	UStaticMeshComponent* DoorFrame;

	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = "Door Components")
	UStaticMeshComponent* LeftDoor;
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = "Door Components")
	UStaticMeshComponent* RightDoor;
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = "Door Components")
	UArrowComponent* Arrow1;
	UPROPERTY(EditAnyWhere, BluePrintReadOnly, Category = "Switch Components")
	USphereComponent* Sphere1;

	UFUNCTION(BluePrintCallable, Category = "Door Function")
	void DoorOpen();
	UFUNCTION(BluePrintCallable, Category = "Door Function")
	void DoorClose();
};
