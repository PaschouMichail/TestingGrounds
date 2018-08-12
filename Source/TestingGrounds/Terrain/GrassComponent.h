// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "GrassComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TESTINGGROUNDS_API UGrassComponent : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	// Constructor
	UGrassComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, Category = Spawning)
	FBox SpawningExtends;

	UPROPERTY(EditDefaultsOnly, Category = Spawning)
	int32 SpawnCount;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Fills the tile with grass
	void SpawnGrass();
};
