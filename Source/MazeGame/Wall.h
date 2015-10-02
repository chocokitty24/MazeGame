// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Wall.generated.h"

UCLASS()
class MAZEGAME_API AWall : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;
	class USceneComponent* DummyRoot2;

	/** StaticMesh component for the clickable block */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* HWallMesh;
	class UStaticMeshComponent* VWallMesh;
	
public:	
	// Sets default values for this actor's properties
	AWall();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot2; }
	/** Returns BlockMesh subobject **/
	FORCEINLINE class UStaticMeshComponent* GetHWallMesh() const { return HWallMesh; }
	FORCEINLINE class UStaticMeshComponent* GetVWallMesh() const { return VWallMesh; }
	
	
};
