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
	bool gameover = false, begun = false, win = false, nowin = false; 
	float t;
	int32 min, sec;
	FTimerHandle Handle;
	void add5();
	void sub5();
	AMyHUD(const class FObjectInitializer &PCIP);
	UFont *HUDFont;
	virtual void BeginPlay() override;
	int i = 400, j = 200;
	int nw = 200;
	float x = 330, y = 150;
	virtual void DrawHUD() override; 
	virtual void Tick(float DeltaTime) override;
	void Draw(); 
	void WinDraw();
	void NoWinDraw();
	
};
