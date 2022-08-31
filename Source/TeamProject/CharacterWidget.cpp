// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "ControlledCharacter.h"

void UCharacterWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCharacterWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (!Owner.IsValid())
	{
		return;
	}

	SetHPText();
	SetHPBar();
}

void UCharacterWidget::SetHPText()
{
	FNumberFormattingOptions Opts;
	Opts.SetMaximumFractionalDigits(0);

	CurrentHPText->SetText(FText::AsNumber(Owner->GetStatus(EStatus::HP), &Opts));
	MaxHPText->SetText(FText::AsNumber(Owner->GetStatusResultValue(EStatus::MaxHP), &Opts));
}

void UCharacterWidget::SetHPBar()
{
	HPPercentage = Owner->GetStatus(EStatus::HP) / Owner->GetStatusResultValue(EStatus::MaxHP);
	HPProgressBar->SetPercent(HPPercentage);

	if (bDisplayOnlyWhenHit)
	{
		DisplayOnlyWhenHit();
	}
}

void UCharacterWidget::DisplayOnlyWhenHit()
{
	HPProgressBar->SetRenderOpacity(0.f);

	if (HPPercentage < 1.f)
	{
		HPProgressBar->SetRenderOpacity(1.f);
	}
}

void UCharacterWidget::OnHit_Implementation()
{
}

void UCharacterWidget::SetOwner(AControlledCharacter* pOwner)
{
	if (IsValid(pOwner))
	{
		Owner = pOwner;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Character Widget : Failed To Set Owner"));
		return;
	}
}

UProgressBar* UCharacterWidget::GetHPBar()
{
	if (IsValid(HPProgressBar))
	{
		return HPProgressBar;
	}

	return nullptr;
}

