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
	bool gameover = false; 
	FTimerHandle Handle;
	AMyHUD(const class FObjectInitializer &PCIP);
	UFont *HUDFont;
	virtual void BeginPlay() override;
	int i = 0, j = 0;
	virtual void DrawHUD() override; 
	virtual void Tick() override;
	void Draw(); 
	
};
