// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"



class UBoxComponent;
class UStaticMeshComponent;
class UCameraComponent;
class UFloatingPawnMovement;
class UArrowComponent;
class USpringArmComponent;


UCLASS()
class L20251103_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	UBoxComponent* Box;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Body;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Left;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* Right;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArm;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	UCameraComponent* Camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	UFloatingPawnMovement* Movement;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	UArrowComponent* Arrow;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	UClass* MyActor;

};
