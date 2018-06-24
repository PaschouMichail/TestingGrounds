// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolComponent.generated.h"
/*
A route card for the patrolling guard to follow
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UPatrolComponent : public UActorComponent
{
	GENERATED_BODY()


protected:
	UPROPERTY(EditInstanceOnly, Category = PatrolRoute)
		TArray<AActor*> PatrolPoints;

public:
	TArray<AActor*> GetPatrolPoints() const;
};
