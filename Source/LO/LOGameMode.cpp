// Copyright Epic Games, Inc. All Rights Reserved.

#include "LOGameMode.h"

#include "UObject/ConstructorHelpers.h"
#include "KHG_STD.h"
#include "LOCharacter/LOCharacter.h"

ALOGameMode::ALOGameMode()
{
	//PlayerControllerClass = ALOPlayerController::StaticClass();
	//DefaultPawnClass = ALOCharacter::StaticClass();
}

void ALOGameMode::PostLogin(APlayerController* NewPlayer)
{
	KLOG_W(TEXT("START"));
	Super::PostLogin(NewPlayer);
	KLOG_W(TEXT("END"));
}
