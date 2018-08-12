// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrainGameMode.h"
#include "EngineUtils.h"
#include "ActorPool.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"

AInfiniteTerrainGameMode::AInfiniteTerrainGameMode()
{
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("NavMeshBoundsPool"));
}

void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	TActorIterator<ANavMeshBoundsVolume> VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());

	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfiniteTerrainGameMode::AddToPool(ANavMeshBoundsVolume *VolumeToAdd)
{
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}


void AInfiniteTerrainGameMode::NewTileConquered()
{
	Score++;
	//UE_LOG(LogTemp, Warning, TEXT("SCORE: %d"), Score)
}