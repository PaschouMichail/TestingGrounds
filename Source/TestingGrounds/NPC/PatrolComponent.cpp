// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC/PatrolComponent.h"

TArray<AActor*> UPatrolComponent::GetPatrolPoints() const
{
	return PatrolPoints;
}
