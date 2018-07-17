// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mannequin.generated.h"

class UCameraComponent;
class USkeletalMeshComponent;
class AGun;

UCLASS()
class TESTINGGROUNDS_API AMannequin : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FPCamera;

	UPROPERTY(VisibleAnywhere, Category = Mesh)
	USkeletalMeshComponent* FPMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gun, meta = (AllowPrivateAccess = "true"))
	AGun* Gun;

protected:
	virtual void BeginPlay() override;

public:
	// Sets default values for this character's properties
	AMannequin();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AGun> GunBlueprint;

	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Fire();

	
	
};