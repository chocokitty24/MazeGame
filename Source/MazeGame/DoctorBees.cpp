// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "DoctorBees.h"


// Sets default values
ADoctorBees::ADoctorBees()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoctorBees::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoctorBees::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ADoctorBees::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

