// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Wall.h"


// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> WallMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> WallMaterial;
		FConstructorStatics()
			: WallMesh(TEXT("/Game/WallMesh.WallMesh"))
			, WallMaterial(TEXT("/Game/WallMaterial.WallMaterial"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh0"));
	WallMesh->SetStaticMesh(ConstructorStatics.WallMesh.Get());
	//Changes shape of wall
	WallMesh->SetRelativeScale3D(FVector(5.f, 1.f, 2.f));
	WallMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	//Sets the starting material color
	WallMesh->SetMaterial(0, ConstructorStatics.WallMaterial.Get());
	WallMesh->SetSimulatePhysics(false);
	WallMesh->AttachTo(DummyRoot);

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

