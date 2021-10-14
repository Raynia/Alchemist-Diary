// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
	PointLight1->Intensity = DesiredIntensity;
	PointLight1->bAddedToSceneVisible = true;
	PointLight1->Intensity = 1200.0f;	
	PointLight1->LightColor = FColor(152, 135, 111);
	RootComponent = PointLight1;

	Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere1->InitSphereRadius(250.0f);
	Sphere1->SetupAttachment(RootComponent);

	Sphere1->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitch::OnOverlabBegin);
	Sphere1->OnComponentEndOverlap.AddDynamic(this, &ALightSwitch::OnOverlabEnd);
}

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightSwitch::OnOverlabBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();		
	}
}

void ALightSwitch::OnOverlabEnd(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightSwitch::ToggleLight()
{
	PointLight1->ToggleVisibility();
}


