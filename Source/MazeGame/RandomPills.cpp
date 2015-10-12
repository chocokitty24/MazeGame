// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "RandomPills.h"
#include "Pill.h"


// Sets default values
ARandomPills::ARandomPills()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	Size = 9;
	PillSpacing = 240.f;
}

// Called when the game starts or when spawned
void ARandomPills::BeginPlay()
{
	Super::BeginPlay();

	int32 NumPills = Size*Size;

	//const FVector PillLocation = FVector(0.f, 0.f, 0.f) + GetActorLocation();

	//if (GEngine)
		//GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, "Start Point: " + PillLocation.ToString());
	for(int32 PillIndex=0; PillIndex<NumPills; PillIndex++){
		const float XOffset = (PillIndex/Size) * PillSpacing; // Divide by dimension
		const float YOffset = (PillIndex%Size) * 195; // Modulo gives remainder

		// Make postion vector, offset from Grid location
		const FVector PillLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		// Spawn a Pill
		APill* NewPill = GetWorld()->SpawnActor<APill>(PillLocation, FRotator(0, 0, 0));
	}
}

// Called every frame
void ARandomPills::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
