// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/// Log out possessed tank
	ATank* PossessedTank = GetControlledTank();
	if (!PossessedTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Possessed Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Possessed Tank %s"), *PossessedTank->GetFName().ToString());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

