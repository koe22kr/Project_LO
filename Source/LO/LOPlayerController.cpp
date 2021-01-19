// Fill out your copyright notice in the Description page of Project Settings.


#include "LOPlayerController.h"
#include "CoreMinimal.h"
#include "Math/UnrealMathUtility.h"




void ALOPlayerController::SetHp(float Value)
{
    this->Hp = Value;
}

void ALOPlayerController::SetAppendHp(float Value)
{
    this->AppendHp = Value;
}