// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the Turret the right amount each frame give max elevation speep and frame rate
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1., 1.);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}