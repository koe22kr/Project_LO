// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LOAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class LOCHARACTER_API ULOAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	ULOAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Action )
	UAnimMontage* AttackMontage;
	void PlayAttackMontage();
private:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category=Character,Meta=(AllowPrivateAccess=true))
	float CurrentSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character, Meta = (AllowPrivateAccess = true))
	bool bIsInAir;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Character, Meta = (AllowPrivateAccess = true))
	bool bIsAiming;
};
