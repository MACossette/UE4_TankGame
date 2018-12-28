// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class AProjectile;

//Enum for aiming State
UENUM()
enum class EFiringStateStatus : uint8
{
	Null,
	Aiming,
	Locked,
	Reloading,
	OutOfAmmo
};

class UTankBarrel;
class UTankTurret;

// Holds Parameters for Barrels
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);


	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FVector HitLocation);

	EFiringStateStatus GetFiringState() const; 

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStateStatus CurrentFiringStatus = EFiringStateStatus::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelMoving();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditAnyWhere, Category = "Firing")
	float LaunchSpeed = 5000;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnyWhere, Category = "Firing")
	float ReloadTimeInSeconds = 3.;

	double LastFireTime = 0;
	FVector AimDirection;

	UPROPERTY(EditAnyWhere, Category = "Firing")
	int32 RoundsLeft = 20;
	
};
