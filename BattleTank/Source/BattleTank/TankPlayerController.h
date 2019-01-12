// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CrosshairYLocation = 0.33333;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LineTraceRange = 1000000.0; // cm


	ATank* GetControlledTank() const;
	
	void BeginPlay() override;

private:


	void Tick(float DeltaTime) override;

	// Start the tank moving the barrel so that a bullet would hit
	// where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT parameter, TRUE if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& OutLookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
