// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Block.h"
#include "BreadCrumbs.h"


// Sets default values
ABlock::ABlock()
{
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> CrumbMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> WhiteMaterial;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> PinkMaterial;
		FConstructorStatics()
			: CrumbMesh(TEXT("/Game/CrumbMesh.CrumbMesh"))
			, WhiteMaterial(TEXT("/Game/MoreWhiteMaterial.MoreWhiteMaterial"))
			, PinkMaterial(TEXT("/Game/DarkPinkMaterial.DarkPinkMaterial"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	BlockMesh->SetStaticMesh(ConstructorStatics.CrumbMesh.Get());
	BlockMesh->SetRelativeScale3D(FVector(1.5, 1.5, 0.1f));
	BlockMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	BlockMesh->SetMaterial(0, ConstructorStatics.WhiteMaterial.Get());
	BlockMesh->AttachTo(DummyRoot);

	// Save a pointer to the orange material
	PinkMaterial = ConstructorStatics.PinkMaterial.Get();

}

void ABlock::Step()
{
	BlockMesh->SetMaterial(0, PinkMaterial);
}

void ABlock::BeginPlay()
{
	Super::BeginPlay();

}
