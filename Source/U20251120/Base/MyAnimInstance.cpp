// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "MyCharacter.h"
#include "Gameframework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"



void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AMyCharacter* Character = Cast<AMyCharacter>(TryGetPawnOwner());
	if (Character)
	{
		GroundSpeed = Character->GetCharacterMovement()->Velocity.Size2D();
		bSprint = Character->bSprint;
		Direction = UKismetAnimationLibrary::CalculateDirection(Character->GetCharacterMovement()->Velocity,
			Character->GetActorRotation());
		AimYaw = Character->GetBaseAimRotation().Yaw;
		AimPitch = Character->GetBaseAimRotation().Pitch;
		bAiming = Character->bAiming;
		bRightLean = Character->bRightLean;
		bLeftLean = Character->bLeftLean;
		bIsCrouched = Character->bIsCrouched;


		float TargetLeanAngle = 0;
		if (bLeftLean)
		{
			TargetLeanAngle = 30.f;
		}
		else if (bRightLean)
		{	
			TargetLeanAngle = -30.f;
		}
		else
		{
			TargetLeanAngle = 0;
		}

		CurrentLeanAngle = FMath::FInterpTo(CurrentLeanAngle, TargetLeanAngle, DeltaSeconds, 8.0f);

		WeaponState = Character->WeaponState;
	}
}

void UMyAnimInstance::AnimNotify_SkeletonNotify()
{
	UE_LOG(LogTemp, Warning, TEXT("AnimNotify_SkeletonNotify"));
}