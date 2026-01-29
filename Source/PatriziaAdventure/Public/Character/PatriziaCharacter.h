// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PatriziaCharacter.generated.h"

struct FInputActionInstance;
struct FInputActionValue;
class UInputAction;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PATRIZIAADVENTURE_API APatriziaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APatriziaCharacter();

protected:

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputAction> Input_Move;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputAction> Input_Look;

	// UPROPERTY(EditAnywhere, Category = "Input")
	// TObjectPtr<class UInputAction> Input_Jump;

	// UPROPERTY(EditAnywhere, Category = "Input")
	// TObjectPtr<class UInputAction> Input_Sprint;

	// UPROPERTY(EditAnywhere, Category = "Input")
	// TObjectPtr<class UInputAction> Input_Attack;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputAction> Input_Crouch;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<class UCameraComponent> CameraComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

	virtual void BeginPlay() override;

	virtual void Move(const FInputActionValue& InValue);

	virtual void Look(const FInputActionInstance& InValue);

	virtual void HandleCrouch();

	virtual void HandleUnCrouch();

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
