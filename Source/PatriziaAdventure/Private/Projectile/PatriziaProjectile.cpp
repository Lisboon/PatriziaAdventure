// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/PatriziaProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"

APatriziaProjectile::APatriziaProjectile()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetSphereRadius(5.0f);
	SphereComponent->SetCollisionProfileName("Projectile");
	RootComponent = SphereComponent;

	LoopedNiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("LoopedNiagaraComponent"));
	LoopedNiagaraComponent->SetupAttachment(SphereComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->InitialSpeed = 1500.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.f;

}

