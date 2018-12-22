// Fill out your copyright notice in the Description page of Project Settings.

#include "TankThruster.h"

UTankThruster::UTankThruster()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankThruster::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	//Calculate the slipping speed
	auto SlippageSpeed = FVector::DotProduct(TankRoot->GetRightVector(), TankRoot->GetComponentVelocity());

	//Workout the necessary acceleration to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * TankRoot->GetRightVector();

	//Calculate and apply sideways force
	
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration)/2.0;
	TankRoot->AddForce(CorrectionForce);

}

void UTankThruster::SetForce(float Force) 
{


	// This is Max force per thruster in Newtons
	// Tank of 40 tons at 1g acceleration

	auto ForceApplied = GetForwardVector() * Force * ThrusterMaxForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
