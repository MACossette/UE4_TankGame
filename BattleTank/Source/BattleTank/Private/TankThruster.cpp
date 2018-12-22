// Fill out your copyright notice in the Description page of Project Settings.

#include "TankThruster.h"


void UTankThruster::SetForce(float Force) 
{


	// This is Max force per thruster in Newtons
	// Tank of 40 tons at 1g acceleration

	auto ForceApplied = GetForwardVector() * Force * ThrusterMaxForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
