// Fill out your copyright notice in the Description page of Project Settings.

#include "TankThruster.h"



UTankThruster::UTankThruster()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankThruster::BeginPlay()
{
	Super::BeginPlay();
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	TankRoot->OnComponentHit.AddDynamic(this, &UTankThruster::OnHit);

}

void UTankThruster::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Drive the thruster
	DriveThrusters();
	// Apply sideways force
	ApplySidewayForce();
	// reset force
	CurrentForce = 0.0;
}

void UTankThruster::ApplySidewayForce()
{
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	//Calculate the slipping speed
	auto SlippageSpeed = FVector::DotProduct(TankRoot->GetRightVector(), TankRoot->GetComponentVelocity());

	//Workout the necessary acceleration to correct
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * TankRoot->GetRightVector();

	//Calculate and apply sideways force

	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2.0;
	TankRoot->AddForce(CorrectionForce);
}

void UTankThruster::SetForce(float Force) 
{
	CurrentForce = FMath::Clamp<float>(CurrentForce + Force, -1.0, 1.0);
}

void UTankThruster::DriveThrusters()
{
	auto ForceApplied = GetForwardVector() * CurrentForce * ThrusterMaxForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
