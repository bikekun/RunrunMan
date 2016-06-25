// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "RunrunMan.h"
#include "RunrunManGameMode.h"
#include "RunrunManCharacter.h"


ARunrunManGameMode::ARunrunManGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/MyPawn"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
