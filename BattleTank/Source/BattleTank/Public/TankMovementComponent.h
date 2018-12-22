// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankThruster;

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Input")
	void InitializeComponent(UTankThruster* LeftThrusterToSet, UTankThruster* RightThruserToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntenededMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntenededTurnRight(float Throw);

private:
	void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	UTankThruster* LeftThruster = nullptr;
	UTankThruster* RightThruster = nullptr;


};
