// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleRotatePlatform.generated.h"

UCLASS()
class OPENMINIWORLD_API ASimpleRotatePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleRotatePlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Start location of the platform
	UPROPERTY(VisibleAnywhere)
	FVector startLocation;

	// Velocity rotation of the platform
	UPROPERTY(EditAnywhere, Category = "Rotate Moving")
	FRotator velocityRotation = FRotator(0, 100, 0);

	// Function to rotate platform
	void RotatePlatform(float DeltaTime);
};
