// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "RandomPills.h"
#include "Pill.h"

APill* Pills[9][9];

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
	int randomX = 0;
	int randomY = 0;
	int randomC = 0;

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

		Pills[(PillIndex % Size)][(PillIndex / Size)] = NewPill;
	}

	for (int x = 0; x < (Size*Size)/2; x++){
		do{
			randomX = rand() % 9;
			randomY = rand() % 9;
		} while (Pills[randomX][randomY]->bHidden);

			Pills[randomX][randomY]->SetActorHiddenInGame(true);
			Pills[randomX][randomY]->SetActorEnableCollision(false);
	}

	for (int x = 0; x < 40; x++){
		do{
			randomX = rand() % 9;
			randomY = rand() % 9;
		} while (Pills[randomX][randomY]->isWhite);

		Pills[randomX][randomY]->isWhite = true;
	}

	for (int x = 0; x < Size; x++){
		for (int y = 0; y < Size; y++){
			if (!(Pills[x][y]->isWhite)){
				randomC = (int)(rand() % 2);
				if (randomC == 1)
					Pills[x][y]->isBlue = true;
				else if (randomC == 0)
					Pills[x][y]->isRed = true;
			}
		}
	}
}

// Called every frame
void ARandomPills::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
