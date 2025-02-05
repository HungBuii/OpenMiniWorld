// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleMovingPlatform.h"

// Sets default values
ASimpleMovingPlatform::ASimpleMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimpleMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	startLocation = GetActorLocation();
}

// Called every frame
void ASimpleMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
}

// Function to move platform
void ASimpleMovingPlatform::MovePlatform(float DeltaTime)
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

bool ASimpleMovingPlatform::HasMovedOutOfDistance() const
{
	return GetDistanceMoved() > distance;
}

float ASimpleMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(startLocation, GetActorLocation());
}

