// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AInfiniteTerrainGameMode : public ATestingGroundsGameMode
{
	GENERATED_BODY()
	
public:
	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = BoundsPool)
	void PopulateBoundsVolumePool();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Scoring)
	int32 Score;

	UFUNCTION(BlueprintCallable, Category = Scoring)
	void NewTileConquered();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;


private:

	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);

};
