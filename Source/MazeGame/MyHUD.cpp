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
	DrawText(TEXT("Begin"), FColor::Black, i, j, HUDFont);
	if (gameover)
		DrawText(TEXT("GAME OVER"), FColor::Black, 50, 50, HUDFont);
	//if (i != 50 && j != 50)
		//GetWorldTimerManager().Pause
	//FCanvasLineItem NewLine(FVector(1, 1, 0), FVector(5, 5, 0));
	//NewLine.SetColor(FColor::Blue);
	//NewLine.LineThickness = 10.f;
	//Canvas->DrawItem(NewLine);
	i++;
	j++;
}
void AMyHUD::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(Handle, this, &AMyHUD::Draw, 20.f, true);
	//Create tick to display remaining time and possibly pause the time until the begin has made it off the screen
	//Destroy the actor when the time runs out with a bool that connects to the actor class from here 
	//in actor fix the calling of the function in block to switch the colors of the breadcrumbs 
}
void AMyHUD::Draw(){
	gameover = true;
	//FString Over = "Game Over";
	//FLinearColor FontC = FLinearColor(1.0f, 1.0f, 1.0f);
	//FCanvasTextItem NewText(FVector2D(50, 50), FText::FromString(Over), HUDFont, FontC);
	//NewText.Scale.Set(5,5);
	//Canvas->DrawItem(NewText);
}



