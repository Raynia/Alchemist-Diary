// ⓒFox Tales Studio


#include "DoubleLeafDoor.h"

// Sets default values
ADoubleLeafDoor::ADoubleLeafDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IsDoorOpened = false;
	OriginLeftDoorDegree = 0.0f;
	OriginRightDoorDegree = 0.0f;

	// 도어 프레임 컴포넌트 설정
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent);
	DoorFrame->SetMobility(EComponentMobility::Static);

	// 좌측 문 컴포넌트 설정
	LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftDoor"));
	LeftDoor->SetupAttachment(DoorFrame);
	LeftDoor->SetMobility(EComponentMobility::Movable);

	// 우측 문 컴포넌트 설정
	RightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightDoor"));
	RightDoor->SetupAttachment(DoorFrame);
	RightDoor->SetMobility(EComponentMobility::Movable);

	// 화살표 컴포넌트 설정
	Arrow1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow1"));
	Arrow1->SetupAttachment(DoorFrame);

	// 상호작용을 위한 구체 컴포턴트 설정
	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
	Sphere1->InitSphereRadius(150.0f);
	Sphere1->SetupAttachment(RootComponent);
	Sphere1->SetMobility(EComponentMobility::Static);
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

void ADoubleLeafDoor::DoorOpen()
{
	FRotator NewLeftDoorRotation = LeftDoor->GetRelativeRotation();
	FRotator NewRightDoorRotation = RightDoor->GetRelativeRotation();
	FRotator ArrowRotation = Arrow1->GetRelativeRotation();

	if (!IsDoorOpened)
	{
		OriginLeftDoorDegree = NewLeftDoorRotation.Yaw;
		OriginRightDoorDegree = NewRightDoorRotation.Yaw;
		IsDoorOpened = true;
	}

	NewLeftDoorRotation.Yaw = ArrowRotation.Yaw;
	NewRightDoorRotation.Yaw = ArrowRotation.Yaw;

	LeftDoor->SetRelativeRotation(NewLeftDoorRotation);
	RightDoor->SetRelativeRotation(NewRightDoorRotation);

}

void ADoubleLeafDoor::DoorClose()
{
	FRotator NewLeftDoorRotation = LeftDoor->GetRelativeRotation();
	FRotator NewRightDoorRotation = RightDoor->GetRelativeRotation();

	if (IsDoorOpened)
	{
		IsDoorOpened = false;
	}

	NewLeftDoorRotation.Yaw = OriginLeftDoorDegree;
	NewRightDoorRotation.Yaw = OriginRightDoorDegree;

	LeftDoor->SetRelativeRotation(NewLeftDoorRotation);
	RightDoor->SetRelativeRotation(NewRightDoorRotation);
}