// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "Avatar.h"


// Sets default values
//Oedipus is the first motherfucker
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

	InputComponent->BindAxis("Yaw", this, &AAvatar::Yaw);
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

void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(200.f*amount*GetWorld()->GetDeltaSeconds());
}
