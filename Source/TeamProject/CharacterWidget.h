// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_API UCharacterWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	TWeakObjectPtr<class AControlledCharacter> Owner;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurrentHPText;

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MaxHPText;

	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HPProgressBar;

	UPROPERTY(EditAnywhere)
		bool bDisplayOnlyWhenHit;

	float HPPercentage;

public:
	UFUNCTION(BlueprintCallable)
	void SetOwner(AControlledCharacter* pOwner);

	UFUNCTION(Blueprintpure)
		class UProgressBar* GetHPBar();

protected:
	void NativeConstruct() override;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	void SetHPText();
	void SetHPBar();

	void DisplayOnlyWhenHit();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void OnHit();
	virtual void OnHit_Implementation();
};
