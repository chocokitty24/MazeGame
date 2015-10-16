// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Wall.h"

//Declaration of Global Variables
int steps;

// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh0"));
	WallMesh->SetStaticMesh(ConstructorStatics.WallMesh.Get());
	//Changes shape of wall
	WallMesh->SetRelativeScale3D(FVector(.5, 2.f, 0.2));
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

void AWall::CanMove(void)
{
	if (orientation){
		if (this->GetActorLocation().Y + 75 < 1449)
			cangoRight = 1;
		else
			cangoRight = 0;
		if (this->GetActorLocation().Y - 75 > 98)
			cangoLeft = 1;
		else
			cangoLeft = 0;
	}else{
		if (this->GetActorLocation().Y + 75 < 1580)
			cangoRight = 1;
		else
			cangoRight = 0;
		if (this->GetActorLocation().Y - 75 > -20)
			cangoLeft = 1;
		else
			cangoLeft = 0;
	}
}

void AWall::MoveWall(bool direction)
{
	CanMove();

	if (direction){
		if (cangoLeft)
			movLeft = 1;
	}else{
		if (cangoRight)
			movRight = 1;
	}
}

// Called every frame
void AWall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector movement;

	if (movLeft){
		movement = this->GetActorLocation() - FVector(0.f, 1.f, 0.f);
		this->SetActorRelativeLocation(movement);
		steps++;
	}else if (movRight){
		movement = this->GetActorLocation() + FVector(0.f, 1.f, 0.f);
		this->SetActorRelativeLocation(movement);
		steps++;
	}

	if (steps > 150){
		movLeft = 0;
		movRight = 0;
		steps = 0;
	}
	
}

