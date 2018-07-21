// Fill out your copyright notice in the Description page of Project Settings.

#include "Mannequin.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Weapons/Gun.h"
#include "Camera/CameraComponent.h"


// Sets default values
AMannequin::AMannequin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Creating First Person Camera component
	FPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FP Camera"));
	FPCamera->SetupAttachment(GetCapsuleComponent());
	FPCamera->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FPCamera->bUsePawnControlRotation = true;

	//Creating First Person Mesh component
	FPMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP Mesh"));
	FPMesh->SetOnlyOwnerSee(true);
	FPMesh->SetupAttachment(FPCamera);
	FPMesh->bCastDynamicShadow = false;
	FPMesh->CastShadow = false;
	FPMesh->RelativeRotation = FRotator(0.f, 0.f, 0.f);
	FPMesh->RelativeLocation = FVector(39.000008f, -1.999917f, -164.f);



}

void AMannequin::BeginPlay()
{
	Super::BeginPlay();

	if (GunBlueprint == NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Gun Blueprint missing!"));
		return;
	}

	Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);

	//Attach gun to FPMesh or TPMesh
	if (IsPlayerControlled()) 
	{
		Gun->AttachToComponent(FPMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));	
	}
	else
	{
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	}

	Gun->FPAnimInstance = FPMesh->GetAnimInstance();
	Gun->TPAnimInstance = GetMesh()->GetAnimInstance();

	//SetupPlayerInputComponent runs before BeginPlay() and the Gun is not instantiated at that point
	//Binding the Fire method now will resolve this problem
	//Only the Player has InputComponent as a class default
	if (InputComponent != NULL)
	{
		InputComponent->BindAction("Fire", IE_Pressed, this, &AMannequin::PullTrigger);
	}
}

void AMannequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMannequin::UnPossessed()
{
	Super::UnPossessed();

	if (Gun != nullptr)
	{
		Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	}
}

void AMannequin::PullTrigger()

{
	Cast<AGun>(Gun)->OnFire();
}

