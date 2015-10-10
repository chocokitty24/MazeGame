// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Maze.h"
#include "Wall.h"


// Sets default values
AMaze::AMaze()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;


	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	HSize = 7;
	VSize = 7;
	GridSpacing1 = 300.f;
	GridSpacing2 = 200.f;
}

// Called when the game starts or when spawned
void AMaze::BeginPlay()
{
	Super::BeginPlay();

	//What actor is this talking about? It is talking about itself
	//RandomBalls.cpp
	//const FVector WallLocation = FVector(10.f, 10.f, 0.f) + GetActorLocation();

	const int32 NumH = (HSize*HSize)+HSize;
	const int32 NumV = (VSize*VSize)+VSize;

	
	// Loop to spawn each block
	for (int32 BlockIndex = 0; BlockIndex<NumH; BlockIndex++)
	{
		const float XOffset = (BlockIndex/HSize) * 240; // Divide by dimension
		const float YOffset = (BlockIndex%HSize) * 200; // Modulo gives remainder
		
		// Make postion vector, offset from Grid location
		const FVector WallLocation = FVector(XOffset+20, YOffset-20, 0.f) + GetActorLocation();
		AWall *NewWall = GetWorld()->SpawnActor<AWall>(WallLocation, FRotator(0, 0, 0));
		// Spawn a block
		//AWall *NewWall = GetWorld()->SpawnActor<AWall>(FVector(0,0,0), FRotator(0, 0, 0));
		//AWall *NewWall2 = GetWorld()->SpawnActor<AWall>(FVector(100,100,0), FRotator(0, 0, 0));

		// Tell the block about its owner
		//if (NewWall != NULL)
		//{
		//	NewWall->OwningGrid = this;
		//}
	} 


	for (int32 BlockIndex = 0; BlockIndex < NumV; BlockIndex++)
	{
		const float XOffset = (BlockIndex/(VSize+1)) * 240; // Divide by dimension
		const float YOffset = (BlockIndex%(VSize+1)) * 193; // Modulo gives remainder
		const FVector WallLocation = FVector(XOffset+135, YOffset-95, 0.f) + GetActorLocation();
		AWall *NewWall = GetWorld()->SpawnActor<AWall>(WallLocation, FRotator(0, 90, 0));

	}
}

// Called every frame
void AMaze::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

