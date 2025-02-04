// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	startLocation = GetActorLocation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (HasMovedOutOfDistance())
	{
		FVector moveDirection = velocityPlatform.GetSafeNormal();
		startLocation += moveDirection * distance;
		SetActorLocation(startLocation);
		velocityPlatform = -velocityPlatform;
		return;
	}
	FVector currentLocation = GetActorLocation();
	currentLocation += velocityPlatform * DeltaTime;
	SetActorLocation(currentLocation);
}

bool AMovingPlatform::HasMovedOutOfDistance() const
{
	return GetDistanceMoved() > distance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(startLocation, GetActorLocation());
}


