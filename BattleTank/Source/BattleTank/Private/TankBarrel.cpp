// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankBarrel.h"
#include "BattleTank.h"




void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount each frame give max elevation speep and frame rate
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1., 1.);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}