// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGame.h"
#include "MyHUD.h"
#include "Avatar.h"

AMyHUD::AMyHUD(const class FObjectInitializer &PCIP):Super(PCIP){
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/Roboto"));
	HUDFont = HUDFontOb.Object;
}

void AMyHUD::add5(){
	t += 5;
	GetWorldTimerManager().SetTimer(Handle, this, &AMyHUD::Draw, t, false);
	GEngine->AddOnScreenDebugMessage(3, 3.f, FColor::Blue, "+5 Secs");
}

void AMyHUD::sub5(){
	t -= 5;
	GetWorldTimerManager().SetTimer(Handle, this, &AMyHUD::Draw, t, false);
	GEngine->AddOnScreenDebugMessage(3, 3.f, FColor::Red, "-5 Secs");
}

void AMyHUD::DrawHUD(){
	FVector2D ScreenSize = FVector2D(Canvas->SizeX, Canvas->SizeY);
	Super::DrawHUD(); 
	DrawText(TEXT("Begin Play"), FColor::Black, i, j, HUDFont, 2.0F, false);
	if (j < 450)
		GetWorldTimerManager().PauseTimer(Handle);
	
	else
		GetWorldTimerManager().UnPauseTimer(Handle);
		min = t / 60;
		sec = t - (60 * min);
		DrawText("Time~ Mins: " + FString::FromInt(min) + " Secs: " + FString::FromInt(sec), FColor::Black, 40, 10, HUDFont, 2.0F, false);
	if(gameover)
		DrawText(TEXT("GAME OVER"), FColor::Black, 350, 200, HUDFont,3.0F,false);
	
	i++;
	j++;
}
void AMyHUD::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(Handle, this, &AMyHUD::Draw, 120.0f, false);
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

void AMyHUD::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	t = GetWorldTimerManager().GetTimerRemaining(Handle);

}



