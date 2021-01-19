// Fill out your copyright notice in the Description page of Project Settings.


#include "LOAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "LOCharacter.h"

ULOAnimInstance::ULOAnimInstance()
{
    this->CurrentSpeed = 0.0f;
    this->bIsInAir = false;
    this->bIsAiming = false;
}

void ULOAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);
    auto Pawn = TryGetPawnOwner();
    if (::IsValid(Pawn))
    {
        CurrentSpeed = Pawn->GetVelocity().Size();
        auto pc = Cast<ALOCharacter>(Pawn);
        if (pc)
        {
            bIsInAir = pc->GetMovementComponent()->IsFalling();
            bIsAiming = pc->IsAiming();
        }
    }
   
    

}
void ULOAnimInstance::PlayAttackMontage()
{
    if (::IsValid(AttackMontage))
    {
        if (!Montage_IsPlaying(AttackMontage))
        {
            Montage_Play(AttackMontage);
        }
    }
}
