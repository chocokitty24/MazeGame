// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGame.h"
#include "Avatar.h"
#include "Block.h"
#include "Pill.h"
//#include "Maze.h"

//UPROPERTY()
//ABlock* BlockClass;
//BlockClass = ObjectInitializer()->CreateDefaultSubobject<ABlock>(this, TEXT("Block"));
// Sets default values
//Oedipus is the first motherfucker
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	invPills = 0;

}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAvatar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	//Super::SetupPlayerInputComponent(InputComponent);

	check(InputComponent);
	InputComponent->BindAxis("Forward", this, &AAvatar::MoveForward);
	InputComponent->BindAxis("Strafe", this, &AAvatar::MoveRight);
	InputComponent->BindAxis("Jump", this, &AAvatar::Jump);
	InputComponent->BindAxis("Yaw", this, &AAvatar::Yaw);
	InputComponent->BindAction("Inventory", IE_Pressed, this, &AAvatar::ToggleInventory);
	this->OnActorHit.AddDynamic(this, &AAvatar::OnHit);
}
void AAvatar::MoveForward(float amount)
{
	if (Controller && amount){
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
	}
}

void AAvatar::MoveRight(float amount)
{
	if (Controller && amount){
		FVector strf = GetActorRightVector();
		AddMovementInput(strf, amount);

	}
}

void AAvatar::Jump(float amount)
{
	if (Controller && amount){
		ACharacter::Jump();
	}

}

void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(200.f*amount*GetWorld()->GetDeltaSeconds());
}
void AAvatar::OnStep(AActor *SelfActor, AActor *OtherActor, FVector NormalInpulse, const FHitResult &Step){
//	UClass* ThisClass = &ABlock::ABlock(); 

	//ThisClass = OtherActor->GetActorClass();
	//if (OtherActor->GetClass()->IsA(ABlock())  )
	ABlock* ThisBlock = Cast<ABlock>(OtherActor);
	//if (ThisBlock){
		ThisBlock->Step();
//	}
}

void AAvatar::OnHit(AActor *SelfActor, AActor *otherActor, FVector NormalInpulse, const FHitResult &Hit){
	if (GEngine){

		APill* PillHit = Cast<APill>(otherActor);

		if (otherActor->GetActorLabel().Contains(TEXT("Pill"), ESearchCase::IgnoreCase, ESearchDir::FromEnd)){
			otherActor->SetActorHiddenInGame(true);
			otherActor->SetActorEnableCollision(false);
			
			if (PillHit->isWhite)
				invPills++;
			else if (PillHit->isRed)
				GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Red, "Ouch! "); //Detract Time
			else if (PillHit->isBlue)
				GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Blue, "Refreshing! "); //Add Time
		}
	}
}

void AAvatar::ToggleInventory()
{
	if (GEngine){
		GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Red, "Number of Pills Collected: ");
		GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Red, FString::FromInt(invPills));


	}
}

//if (otherActor->GetClass()->GetDefaultObject<APill>()->isWhite == true)
//APill* PillHit = FindObject<APill>(classPackage, otherActor->GetClass()->GetName());
