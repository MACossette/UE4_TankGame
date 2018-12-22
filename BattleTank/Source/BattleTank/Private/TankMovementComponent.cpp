// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "../Public/TankThruster.h"

void UTankMovementComponent::InitializeComponent(UTankThruster* LeftThrusterToSet, UTankThruster* RightThruserToSet)
{
	if (!ensure(LeftThrusterToSet && RightThruserToSet)) { return; }
	LeftThruster = LeftThrusterToSet;
	RightThruster = RightThruserToSet;

}

void UTankMovementComponent::IntenededMoveForward(float Throw)
{
	LeftThruster->SetForce(Throw);
	RightThruster->SetForce(Throw);

	// TODO Prevent double speed
}

void UTankMovementComponent::IntenededTurnRight(float Throw)
{
	LeftThruster->SetForce(Throw);
	RightThruster->SetForce(-Throw);

	// TODO Prevent double speed
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	//No Need to call super:: as we are replacing a function

	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntenededMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;

	IntenededTurnRight(RightThrow);

}
