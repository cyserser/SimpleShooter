// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

// Called when the game starts or when spawned
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
    
    if(AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);

        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());

    }
}

// Called every frame
void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


    if(LineOfSightTo(PlayerPawn))
    {
       GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
       GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
    }
    else 
    {
       GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
    }
    
    
}