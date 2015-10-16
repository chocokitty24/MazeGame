// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "BreadCrumbs.h"
#include "Block.h"


// Sets default values
ABreadCrumbs::ABreadCrumbs()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;
	// Set defaults
	Size = 9;
	//BlockSpacing =230.f;
}

// Called when the game starts or when spawned
void ABreadCrumbs::BeginPlay()
{
	Super::BeginPlay();
	// Number of blocks
	const int32 NumBlocks = Size * Size;

	// Loop to spawn each block
	for (int32 BlockIndex = 0; BlockIndex<NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex / Size) * 240; // Divide by dimension
		const float YOffset = (BlockIndex%Size) * 195; // Modulo gives remainder

		// Make postion vector, offset from Grid location
		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		// Spawn a block
		ABlock* NewBlock = GetWorld()->SpawnActor<ABlock>(BlockLocation, FRotator(0, 0, 0));
		NewBlock->SetActorHiddenInGame(true);
		//NewBlock->SetActorEnableCollision(true);

	}
}


