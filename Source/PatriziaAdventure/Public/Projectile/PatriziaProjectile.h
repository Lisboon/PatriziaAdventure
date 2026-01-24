// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatriziaProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraComponent;

UCLASS()
class PATRIZIAADVENTURE_API APatriziaProjectile : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")

	TObjectPtr<UNiagaraComponent> LoopedNiagaraComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovementComponent;


public:

	APatriziaProjectile();

};
