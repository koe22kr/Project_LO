// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "LOItem.generated.h"

/**
 * 
 */
UENUM()
enum class EItemType :uint8
{
	NONE,
	EQUIP,
	CONSUME,
};

UENUM()
enum class EEffectType :uint8
{
	NONE,
	HP,
};

USTRUCT( BlueprintType)
struct FItemInfo : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
	FString ThumbnailPath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
	FString ModelPath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
	EItemType ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
	int EffectCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
	TArray< EEffectType> EffectTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
	TArray<int> EffectValues;
	

};


class LO_API LOItem
{
public:
	
	LOItem();
	~LOItem();
};
