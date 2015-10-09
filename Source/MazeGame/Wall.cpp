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
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> HWallMesh;
		//ConstructorHelpers::FObjectFinderOptional<UStaticMesh> VWallMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> WallMaterial;
		FConstructorStatics()
			: HWallMesh(TEXT("/Game/HWallMesh.HWallMesh"))
			//, VWallMesh(TEXT("/Game/VWallMesh.VWallMesh"))
			, WallMaterial(TEXT("/Game/WallMaterial.WallMaterial"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;
	//DummyRoot2 = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy1"));
	//RootComponent = DummyRoot2;

	// Create static mesh component
	/* VWallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh0"));
	VWallMesh->SetStaticMesh(ConstructorStatics.VWallMesh.Get());
	//Changes shape of wall
	VWallMesh->SetRelativeScale3D(FVector(2.f, 1.f, 2.f));
	VWallMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	//Sets the starting material color
	VWallMesh->SetMaterial(0, ConstructorStatics.WallMaterial.Get());
	VWallMesh->SetSimulatePhysics(false);
	VWallMesh->AttachTo(DummyRoot);*/

	HWallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh0"));
	HWallMesh->SetStaticMesh(ConstructorStatics.HWallMesh.Get());
	//Changes shape of wall
	HWallMesh->SetRelativeScale3D(FVector(.5, 2.f, 2.f));
	HWallMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	//Sets the starting material color
	HWallMesh->SetMaterial(0, ConstructorStatics.WallMaterial.Get());
	HWallMesh->SetSimulatePhysics(false);
	HWallMesh->AttachTo(DummyRoot);

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

