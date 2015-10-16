// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Doc.h"


// Sets default values
ADoc::ADoc()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<USkeletalMesh> PlayerMesh;

		FConstructorStatics()
			: PlayerMesh(TEXT("/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin.SK_Mannequin"))
		{
		}
	};


	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerMesh0"));
	PlayerMesh->SetSkeletalMesh(ConstructorStatics.PlayerMesh.Get());


	PlayerMesh->SetSimulatePhysics(false);
	this->SetActorEnableCollision(true);

}

// Called when the game starts or when spawned
void ADoc::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoc::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

