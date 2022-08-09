// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterCharacter.h"

// Called when the game starts or when spawned
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
    
    if(AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
    }
}

// Called every frame
void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    

    // if(LineOfSightTo(PlayerPawn))
    // {
    //     SetFocus(PlayerPawn);
    //     MoveToActor(PlayerPawn, AcceptanceRadius);
    // }
    // else 
    // {
    //    ClearFocus(EAIFocusPriority::Gameplay);
    //    StopMovement();
    // }
    
    
}