// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PatriziaCharacter.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


APatriziaCharacter::APatriziaCharacter()
{
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetupAttachment(GetMesh(), FName("WeaponSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetCharacterMovement()->GetNavAgentPropertiesRef().bCanCrouch = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

}

void APatriziaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APatriziaCharacter::Move(const FInputActionValue& InValue)
{
	FVector2D InputValue = InValue.Get<FVector2D>();

	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;

	AddMovementInput(ControlRot.Vector(), InputValue.X);

	FVector RightDirection = ControlRot.RotateVector(FVector::RightVector);
	AddMovementInput(RightDirection, InputValue.Y);
}

void APatriziaCharacter::Look(const FInputActionInstance& InValue)
{
	FVector2D LookAxisValue = InValue.GetValue().Get<FVector2D>();

	AddControllerYawInput(LookAxisValue.X);

	AddControllerPitchInput(LookAxisValue.Y);

}

void APatriziaCharacter::HandleCrouch()
{
	ACharacter::Crouch();
}

void APatriziaCharacter::HandleUnCrouch()
{
	ACharacter::UnCrouch();
}

void APatriziaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	EnhancedInput->BindAction(Input_Move, ETriggerEvent::Triggered, this, &APatriziaCharacter::Move);

	EnhancedInput->BindAction(Input_Look, ETriggerEvent::Triggered, this, &APatriziaCharacter::Look);

	EnhancedInput->BindAction(Input_Crouch, ETriggerEvent::Started, this, &APatriziaCharacter::HandleCrouch);
	EnhancedInput->BindAction(Input_Crouch, ETriggerEvent::Completed, this, &APatriziaCharacter::HandleUnCrouch);
}


