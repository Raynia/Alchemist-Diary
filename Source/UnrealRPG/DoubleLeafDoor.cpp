// ⓒFox Tales Studio


#include "DoubleLeafDoor.h"

// Sets default values
ADoubleLeafDoor::ADoubleLeafDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoubleLeafDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoubleLeafDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoubleLeafDoor::OnOverlabBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void ADoubleLeafDoor::OnOverlabEnd(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ADoubleLeafDoor::DoorOpen(UStaticMeshComponent* TargetComponent, int DoorPosition)
{

}

void ADoubleLeafDoor::DoorClose(UStaticMeshComponent* TargetComponent, int DoorPosition)
{

}