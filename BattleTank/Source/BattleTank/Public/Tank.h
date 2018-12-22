// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankThruster;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

public:	

	void BeginPlay();

private:
	UPROPERTY(EditAnyWhere, Category = "Firing")
	float LaunchSpeed = 100000; // TODO find sensible default

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr;

	UPROPERTY(EditAnyWhere, Category = "Firing")
	float ReloadTimeInSeconds = 3.;

	double LastFireTime = 0;
};
