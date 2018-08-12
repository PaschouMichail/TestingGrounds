// Fill out your copyright notice in the Description page of Project Settings.

#include "GrassComponent.h"

UGrassComponent::UGrassComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGrassComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UGrassComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnGrass();
}


void UGrassComponent::SpawnGrass()
{
	for (size_t i = 0; i < SpawnCount; i++)
	{
		FVector Location = FMath::RandPointInBox(SpawningExtends);
		AddInstance(FTransform(Location));
	}
}