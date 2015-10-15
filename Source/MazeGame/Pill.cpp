// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Pill.h"


// Sets default values
APill::APill()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	isWhite = false;
	isBlue = false;
	isRed = false;

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PillMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> PillMaterial;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> BluePillMaterial;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> RedPillMaterial;
		FConstructorStatics()
			: PillMesh(TEXT("/Game/PillMesh.PillMesh"))
			, PillMaterial(TEXT("/Game/PillMaterial.PillMaterial"))
			, RedPillMaterial(TEXT("/Game/MoreRedMaterial.MoreRedMaterial"))
			, BluePillMaterial(TEXT("/Game/MoreBlueMaterial.MoreBlueMaterial"))
		{
		}
	};

	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	RedMaterial = ConstructorStatics.RedPillMaterial.Get();
	BlueMaterial = ConstructorStatics.BluePillMaterial.Get();

	int random = rand() % 5;

	// Create static mesh component
	PillMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PillMesh0"));
	PillMesh->SetStaticMesh(ConstructorStatics.PillMesh.Get());
	PillMesh->SetRelativeScale3D(FVector(.5, .5, .5));
	PillMesh->SetRelativeLocation(FVector(130.f, 0.f, 0.f));


	PillMesh->SetSimulatePhysics(false);

	/*if (random == 1){
		PillMesh->SetMaterial(0, RedMaterial);
	}
	else if (random == 0){
		PillMesh->SetMaterial(0, BlueMaterial);
	}*/

	PillMesh->AttachTo(DummyRoot);
}

// Called when the game starts or when spawned
void APill::BeginPlay()
{
	Super::BeginPlay();

	if (isRed)
		PillMesh->SetMaterial(0, RedMaterial);
	else if (isBlue)
		PillMesh->SetMaterial(0, BlueMaterial);

}

// Called every frame
void APill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

