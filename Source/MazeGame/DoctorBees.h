// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "DoctorBees.generated.h"

UCLASS()
class MAZEGAME_API ADoctorBees : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADoctorBees();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
