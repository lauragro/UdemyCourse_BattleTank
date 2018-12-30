// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	/// Log out possessed tank
	ATank* PossessedTank = GetControlledTank();
	if (!PossessedTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No Possessed Tank")); 
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed Tank %s"), *PossessedTank->GetFName().ToString());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get world location of line through crosshair
	// If we hit the landscape
	// Then tell the controlled tank to aim at this point
}

