// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 8000.0;

private:

public:
	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
};
