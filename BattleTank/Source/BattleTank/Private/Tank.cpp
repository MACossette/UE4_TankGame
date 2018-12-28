// Fill out your copyright notice in the Description page of Project Settings.



#include "../Public/Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	int32 Damagepoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp<int32>(DamageAmount, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;

	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}

	return DamageToApply;
}

float ATank::GetHealthPercent() const
{
	// (float)VariableInt32 allows to cast to a float
	return (float)CurrentHealth / (float)StartingHealth;
}
