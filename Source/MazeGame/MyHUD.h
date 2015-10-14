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
	AMyHUD(const class FObjectInitializer &PCIP);
	UFont *HUDFont;
	int i = 0, j = 0;
	virtual void DrawHUD() override; 
	
};
