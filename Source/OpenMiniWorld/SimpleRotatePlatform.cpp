// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleRotatePlatform.h"

// Sets default values
ASimpleRotatePlatform::ASimpleRotatePlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimpleRotatePlatform::BeginPlay()
{
	Super::BeginPlay();
	
	startLocation = GetActorLocation();
}

// Called every frame
void ASimpleRotatePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotatePlatform(DeltaTime);
}

// Function to rotate platform
void ASimpleRotatePlatform::RotatePlatform(float DeltaTime)
{
	FRotator currentRotation = GetActorRotation();
	currentRotation += velocityRotation * DeltaTime;
	SetActorRotation(currentRotation);
}

