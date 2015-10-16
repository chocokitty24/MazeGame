// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class MAZEGAME_API AMyHUD : public AHUD
{
	GENERATED_BODY()
public:
	AMyHUD();
	bool gameover = false, begun = false; 
	float t;
	int32 min, sec;
	FTimerHandle Handle;
	void add5();
	void sub5();
	AMyHUD(const class FObjectInitializer &PCIP);
	UFont *HUDFont;
	virtual void BeginPlay() override;
	int i = 400, j = 200;
	virtual void DrawHUD() override; 
<<<<<<< HEAD
	virtual void Tick(float DeltaTime) override;
=======
	//virtual void Tick() override;
>>>>>>> origin/master
	void Draw(); 
	
};
