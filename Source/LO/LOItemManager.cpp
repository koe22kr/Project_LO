// Fill out your copyright notice in the Description page of Project Settings.


#include "LOItemManager.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "Math/UnrealMathUtility.h"
#include "KHG_STD.h"
#include "LOItem.h"
#include "LOPlayerController.h"


// Sets default values
ALOItemManager::ALOItemManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	ConstructorHelpers::FObjectFinder<UDataTable> DataTable(TEXT("DataTable'/Game/ItemTable.ItemTable'"));
	if (DataTable.Succeeded())
	{
		ItemTable = DataTable.Object;
	}
}

// Called when the game starts or when spawned
void ALOItemManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALOItemManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ALOItemManager::TryUseItem(int ItemId, APlayerController* Target)
{
	FItemInfo* info = ItemTable->FindRow<FItemInfo>(FName(FString::FormatAsNumber(ItemId)), FString(""));
	if (info != nullptr && ::IsValid(Target))
	{
		KLOG_W(info->Name);
		ItemEffect(info, Target);
		return true;
	}
	return false;
}

void ALOItemManager::ItemEffect(FItemInfo* Info, APlayerController* Target)
{
	ALOPlayerController* target = Cast<ALOPlayerController>(Target);
	if (target == nullptr)
	{
		return;
	}

	for (int i = 0; i < Info->EffectCount; i++)
	{
		if (Info->EffectTypes.Num() <= i && Info->EffectValues.Num() <= i)
		{
			KLOG_W("ItemTable EffectTypes or Values is wrong");
			return;
		}
		
		switch (Info->EffectTypes[i])
		{
			case EEffectType::HP:
			{
				CalcHpRelative(Info->EffectValues[i], target);
			}break;
		}
	}
}
	void ALOItemManager::CalcHp(float Value, APlayerController * Target)
	{
		ALOPlayerController* target = Cast<ALOPlayerController>(Target);
		if (target == nullptr)
		{
			return;
		}
		target->SetHp(FMath::Clamp(Value, 0.0f, target->GetMaxHp()));
	}
	void ALOItemManager::CalcHpRelative(float Value, APlayerController* Target)
	{
		ALOPlayerController* target = Cast<ALOPlayerController>(Target);
		if (target == nullptr)
		{
			return;
		}
		target->SetHp(FMath::Clamp(target->GetHp() + Value, 0.0f, target->GetMaxHp()));
	}