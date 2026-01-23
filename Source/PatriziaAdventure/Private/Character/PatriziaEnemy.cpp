// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PatriziaEnemy.h"

APatriziaEnemy::APatriziaEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

}

void APatriziaEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void APatriziaEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APatriziaEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

