// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "MyHUD.h"

AMyHUD::AMyHUD(const class FObjectInitializer &PCIP):Super(PCIP){
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/Roboto"));
	HUDFont = HUDFontOb.Object;
}

void AMyHUD::DrawHUD(){
	FVector2D ScreenSize = FVector2D(Canvas->SizeX, Canvas->SizeY);
	Super::DrawHUD();
	DrawText(TEXT("Hello"), FColor::Black, 0, 0, HUDFont);
	FCanvasLineItem NewLine(FVector(1, 1, 0), FVector(1, 5, 0));
	NewLine.SetColor(FColor::Blue);
	NewLine.LineThickness = 10.f;
	Canvas->DrawItem(NewLine);
}

