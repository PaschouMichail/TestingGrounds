// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/PatrollingGuard.h"


TArray<AActor*> APatrollingGuard::GetPatrolPoints()
{
	return PatrolPointsCPP;
}

