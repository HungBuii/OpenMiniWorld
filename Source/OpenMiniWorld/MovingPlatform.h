// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OPENMINIWORLD_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Velocity of the platform
	UPROPERTY(EditAnywhere)
	FVector velocityPlatform = FVector(0, 0, 100);

	// Start location of the platform
	UPROPERTY(VisibleAnywhere)
	FVector startLocation;

	// Distance the platform can be moved
	UPROPERTY(VisibleAnywhere)
	float distance = 100;


	// Function to get distance moved
	float GetDistanceMoved() const;

	// Function to check if the platform has moved out the distance
	bool HasMovedOutOfDistance() const;

	// Function to move platform
	void MovePlatform(float DeltaTime);
};
