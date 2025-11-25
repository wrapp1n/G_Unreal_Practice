// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseHUD.h"
#include "MyCharacter.h"
#include "MyAnimInstance.h"
#include "Engine/Canvas.h"

void ABaseHUD::DrawHUD()
{
	Super::DrawHUD();

	AMyCharacter* Character = Cast<AMyCharacter>(GetOwningPlayerController()->GetPawn());
	if (Character)
	{
		bMoving = Character->bMoving;

	}

	int32 UnitX = Canvas->SizeX / 100;
	int32 UnitY = Canvas->SizeY / 100;
	int32 CenterX = Canvas->SizeX / 2;
	int32 CenterY = Canvas->SizeY / 2;
	int32 DrawSize = 4;

	float Gap = 10.0f;       // 중앙이 벌어질 정도
	float LineLength = DrawSize; // 기존 선 길이


	if (bMoving)
	{

		Draw2DLine(
			CenterX - (UnitX * DrawSize) - Gap,  // 왼쪽 끝
			CenterY,
			CenterX - Gap,                       // 중앙 왼쪽 경계
			CenterY,
			FColor::Green
		);

		Draw2DLine(
			CenterX + Gap,                       // 중앙 오른쪽 경계
			CenterY,
			CenterX + (UnitX * DrawSize) + Gap,  // 오른쪽 끝
			CenterY,
			FColor::Green
		);

		Draw2DLine(
			CenterX,
			CenterY - (UnitX * DrawSize) - Gap,  // 위쪽 끝
			CenterX,
			CenterY - Gap,                       // 중앙 위 경계
			FColor::Green
		);

		Draw2DLine(
			CenterX,
			CenterY + Gap,                       // 중앙 아래 경계
			CenterX,
			CenterY + (UnitX * DrawSize) + Gap,  // 아래쪽 끝
			FColor::Green
		);
	}
	else
	{
		DrawSize = 4;

		Draw2DLine(CenterX - (UnitX * DrawSize),
			CenterY,
			CenterX + (UnitX * DrawSize),
			CenterY,
			FColor::Green);

		Draw2DLine(CenterX,
			CenterY - (UnitX * DrawSize),
			CenterX,
			CenterY + (UnitX * DrawSize),
			FColor::Green);
	}

}