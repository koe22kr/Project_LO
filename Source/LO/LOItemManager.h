// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LOItemManager.generated.h"

class APlayerController;
struct FItemInfo;
class UDataTable;
UCLASS()
class LO_API ALOItemManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALOItemManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UFUNCTION(BlueprintCallable)
	bool TryUseItem(int ItemId, APlayerController* Target);

	void ItemEffect(FItemInfo* Info, APlayerController* Target);
	UPROPERTY(VisibleAnywhere)
	UDataTable* ItemTable;
	void CalcHp(float Value, APlayerController* Target);
	void CalcHpRelative(float Value, APlayerController* Target);
};
