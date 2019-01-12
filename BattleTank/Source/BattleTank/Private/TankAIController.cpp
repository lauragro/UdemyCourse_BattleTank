// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/// Log out possessed tank
	ATank* FoundTank = GetPlayerTank();
	if (!FoundTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Tank found no Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank found Player Tank %s"), *FoundTank->GetFName().ToString());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO move towards player

		// get vector to move straight toward player
		// if no obstacles between here and next move location
		// then move
		// otherwise move away from obstacle

		// aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// TODO fire if ready
	}
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}