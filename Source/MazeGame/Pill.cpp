// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Pill.h"


// Sets default values
APill::APill()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PillMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> PillMaterial;
		FConstructorStatics()
			: PillMesh(TEXT("/Game/PillMesh.PillMesh"))
			, PillMaterial(TEXT("/Game/PillMaterial.PillMaterial"))
		{
		}
	};

	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	PillMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PillMesh0"));
	PillMesh->SetStaticMesh(ConstructorStatics.PillMesh.Get());
	PillMesh->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
	PillMesh->SetRelativeLocation(FVector(0.f, 0.f, 25.f));

	PillMesh->SetSimulatePhysics(true);

	PillMesh->AttachTo(DummyRoot);
}

// Called when the game starts or when spawned
void APill::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

