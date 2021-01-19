// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LOPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class LO_API ALOPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = Info, Meta = (AllowPrivateAccess = true))
	float DefaulttHp;
	UPROPERTY(EditAnywhere, Category = Info, Meta = (AllowPrivateAccess = true))
	float DefaultMaxHp;
	UPROPERTY(EditAnywhere, Category = Info, Meta = (AllowPrivateAccess = true))
	float AppendHp;
	UPROPERTY(EditAnywhere, Category = Info, Meta = (AllowPrivateAccess = true))
	float Hp;
public:
	
	const float GetHp() { return Hp; };
	void SetHp(float Value);
	const float GetMaxHp() { return DefaultMaxHp + AppendHp; }
	void SetAppendHp(float Value);
};
