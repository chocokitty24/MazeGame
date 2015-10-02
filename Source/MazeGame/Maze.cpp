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

	HSize = 5;
	VSize = 5;
	GridSpacing = 2.f;

}

// Called when the game starts or when spawned
void AMaze::BeginPlay()
{
	Super::BeginPlay();

	//What actor is this talking about? It is talking about itself
	//RandomBalls.cpp
	const FVector WallLocation = FVector(10.f, 10.f, 0.f) + GetActorLocation();

	AWall *NewWall = GetWorld()->SpawnActor<AWall>(WallLocation, FRotator(0, 0, 0));
	
}

// Called every frame
void AMaze::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

