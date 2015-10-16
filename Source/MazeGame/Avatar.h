// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Avatar.generated.h"



UCLASS()
class MAZEGAME_API AAvatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAvatar();

	int invPills;
	//bool add5=false, sub5=false;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//Hello Will says this comment
	void MoveForward(float amount);
	void MoveRight(float amount);
	void Jump(float amount);

	void Yaw(float amount);

	void ToggleInventory();

	UFUNCTION()
	void OnHit(AActor *SelfActor, AActor *otherActor, FVector NormalInpulse, const FHitResult &Hit);
	
};
