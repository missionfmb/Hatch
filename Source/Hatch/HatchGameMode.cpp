// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HatchGameMode.h"
#include "HatchHUD.h"
#include "HatchCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHatchGameMode::AHatchGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHatchHUD::StaticClass();
}
