// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LOGameMode.generated.h"

UCLASS()
class ALOGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALOGameMode();
	virtual void PostLogin(APlayerController* NewPlayer) override;
};



