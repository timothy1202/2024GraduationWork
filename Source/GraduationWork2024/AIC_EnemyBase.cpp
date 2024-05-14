// Fill out your copyright notice in the Description page of Project Settings.


#include "AIC_EnemyBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "EnemyBase.h"

AAIC_EnemyBase::AAIC_EnemyBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	
}

void AAIC_EnemyBase::BeginPlay()
{
	Super::BeginPlay();

}

void AAIC_EnemyBase::ExecuteBT(UBehaviorTree* const BT)
{
	if (BT)
	{
		UBlackboardComponent* myBlackboard;
		UseBlackboard(BT->BlackboardAsset, myBlackboard);
		Blackboard = myBlackboard;
		RunBehaviorTree(BT);
	}
}

void AAIC_EnemyBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime); 

   /* if (IsValid(myPawn))
    {
        if (myPawn->HighestATPTarget != highest_ATP_target)
        {
            highest_ATP_target = myPawn->HighestATPTarget;

            UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
            if (BlackboardComp)
            {
                BlackboardComp->SetValueAsObject("AttackTarget", highest_ATP_target);
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("myPawn is not valid"));
    }*/
}


USkeletalMeshComponent* AAIC_EnemyBase::GetMeshComponent() const
{
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn)
	{
		USkeletalMeshComponent* MeshComponent = Cast<USkeletalMeshComponent>(ControlledPawn->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
		return MeshComponent;
	}
	return nullptr;
}
