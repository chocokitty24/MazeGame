// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Wall.h"

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
		if (this->GetActorLocation().X + 100 + 130 < 2020){
			cangoRight = 1;
		}
		else{
			cangoRight = 0;
		}
		if (this->GetActorLocation().X - (100 +130) > 35){
			cangoLeft = 1;
		}else{
			cangoLeft = 0;
		}
	}
	else{
		if (this->GetActorLocation().Y + 100 + 150 < 1680){
			cangoRight = 1;
		}
		else{
			cangoRight = 0;
		}
		if (this->GetActorLocation().Y - (100 + 150) > -120){
			cangoLeft = 1;
		}else{
			cangoLeft = 0;
		}
	}
}

void AWall::MoveWall(bool direction)
{
	if (direction){
		movLeft = 1;
	}else{
		movRight = 1;
	}
}

// Called every frame
void AWall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector Vstep = FVector(1.f, 0.f, 0.f);
	FVector Hstep = FVector(0.f, 1.f, 0.f);

	if (orientation){
		steps++;
		if (steps > 100){
			movLeft = 0;
			movRight = 0;
			steps = 0;
		}
		if (movLeft){
			if(this->GetActorLocation().X - Vstep.X > -1800){
				this->SetActorRelativeLocation(GetActorLocation() - Vstep);
			}
		}else if(movRight){
			if(this->GetActorLocation().X + Vstep.X < 800){
				this->SetActorRelativeLocation(this->GetActorLocation() + Vstep);
			}
		}
	}else if (!orientation){
		steps++;
		if (steps > 115){
			movLeft = 0;
			movRight = 0;
			steps = 0;
		}
		if (movLeft){
			if(this->GetActorLocation().Y - Hstep.Y > -200){
				this->SetActorRelativeLocation(this->GetActorLocation() - Hstep);
			}
		}else if(movRight){
			if(this->GetActorLocation().Y + Hstep.Y < 1000){
				this->SetActorRelativeLocation(this->GetActorLocation() + Hstep);
			}
		}
	}
}


