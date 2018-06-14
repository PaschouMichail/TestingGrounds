// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/ChooseNextWaypoint.h"
#include "TestingGrounds.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "Public/PatrollingGuard.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get PatrolPoints
	auto AIController = OwnerComp.GetAIOwner();
	auto PatrolPoints = Cast<APatrollingGuard>(AIController->GetPawn())->GetPatrolPoints();

	//Set Waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	auto Waypoint = PatrolPoints[Index];
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, Waypoint);
	
	//Cycle Index
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index + 1) % PatrolPoints.Num());

	UE_LOG(LogTemp, Warning, TEXT("Index = %i"), Index)
	
	return EBTNodeResult::Succeeded;
}


