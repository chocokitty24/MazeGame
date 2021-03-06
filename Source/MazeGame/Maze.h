// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Maze.generated.h"

UCLASS()
class MAZEGAME_API AMaze : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;
	
public:	
	// Sets default values for this actor's properties
	AMaze();

	FTimerHandle mhandle;
	bool openexit;

	UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadOnly)
		int32 Size;

	//finds the roots of two cells for disjoint set
	int FindRoot(int root, int cells[]);
	
	//Rmoves the walls to create the maze
	void RemoveWalls(void);
	void RemoveExit(void);

	//Moves walls for an organic maze that is constantly changing
	void Organic(void);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	
};
