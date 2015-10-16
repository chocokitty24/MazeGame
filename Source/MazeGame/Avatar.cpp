// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGame.h"
#include "Avatar.h"
#include "Block.h"
#include "Pill.h"
#include "MyHUD.h"
#include "Doc.h"
#include "Wall.h"

AActor* WallActor = NULL;

AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

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
	InputComponent->BindAction("Bomb", IE_Pressed, this, &AAvatar::BombWall);
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
	AddControllerYawInput(100.f*amount*GetWorld()->GetDeltaSeconds());
}

void AAvatar::OnHit(AActor *SelfActor, AActor *otherActor, FVector NormalInpulse, const FHitResult &Hit){
	if (GEngine){
		if (otherActor->GetActorLabel().Contains(TEXT("Block"), ESearchCase::IgnoreCase, ESearchDir::FromEnd)){

			ABlock* ThisBlock = Cast<ABlock>(otherActor);
			ThisBlock->Step();
		}
		APill* PillHit = Cast<APill>(otherActor);
		//AMyHUD*	HUD = Cast<AMyHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		AMyHUD* HUD = Cast<AMyHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		if (otherActor->GetActorLabel().Contains(TEXT("Pill"), ESearchCase::IgnoreCase, ESearchDir::FromEnd)){
			otherActor->SetActorHiddenInGame(true);
			otherActor->SetActorEnableCollision(false);
			
			if (PillHit->isWhite)
				invPills++;
			else if (PillHit->isRed){
				GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Red, "Ouch! "); //Detract Time
				HUD->sub5();
			}else if (PillHit->isBlue){
				GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Blue, "Refreshing! "); //Add Time
				HUD->add5();
			}
		}
		if (otherActor->GetActorLabel().Contains(TEXT("Doc"), ESearchCase::IgnoreCase, ESearchDir::FromEnd)){
			if (invPills < 10)
				GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Red, "Sorry! Not enough pills! Go find me some more! ");
			else
				GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Blue, "YOU'RE CURED! YAY");

		}

		AWall* WallHit = Cast<AWall>(otherActor);
		if (otherActor->GetActorLabel().Contains(TEXT("Wall"), ESearchCase::IgnoreCase, ESearchDir::FromEnd)){
			WallActor = otherActor;
			if (invPills < 10)
				GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Red, "Sorry! Not enough Pills! Go find me some more ");
			else
				GEngine->AddOnScreenDebugMessage(0, 3.f, FColor::Blue, "YOU'RE CURED! YAY");
			
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

void AAvatar::BombWall(void){
	TArray<AActor*> OverlapActors;
	UClass* filter = 0;
	
		if (invPills >= 2){
		GetOverlappingActors(OverlapActors, filter);
		if (OverlapActors.Find(WallActor)){
			WallActor->SetActorHiddenInGame(true);
			WallActor->SetActorEnableCollision(false);
			invPills = invPills - 2;
			
		}
		
	}
		else{
			GEngine->AddOnScreenDebugMessage(1, 3.f, FColor::Red, "Sorry! Not enough pills to break the wall! Go get more");
			
		}
	}