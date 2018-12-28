// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Projectile.generated.h"


UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LaunchProjectile(float Speed);

private:
	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit);

	void OnTimerExpire();
	
	UPROPERTY(VisibleAnywhere, Category = "Component")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float DestroyDelay = 10.0;

	UPROPERTY(EditAnywhere, Category = "Setup")
	float ProjectileDamage = 20.0;
};
