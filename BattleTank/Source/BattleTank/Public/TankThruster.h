// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankThruster.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankThruster : public UStaticMeshComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetForce(float Force);

private:
	UTankThruster();

	virtual void BeginPlay() override;

	void ApplySidewayForce();

	void DriveThrusters();

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);

	UPROPERTY(EditAnywhere, Category = "Setup")
	float ThrusterMaxForce = 60000000.0;

	float CurrentForce = 0.0;
	
};
