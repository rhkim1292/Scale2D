// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "CPP_Scale2DPaperCharacterBase.generated.h"

/**
 * 
 */
UCLASS()
class SCALE2D_API ACPP_Scale2DPaperCharacterBase : public APaperCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	public:
		ACPP_Scale2DPaperCharacterBase();
		
		//Ability System Component
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
		class UAbilitySystemComponent* AbilitySystemComponent;

		virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilitySystem")
		EGameplayEffectReplicationMode ASCReplicationMode = EGameplayEffectReplicationMode::Mixed;
		virtual void PossessedBy(AController* NewController) override;
		virtual void OnRep_PlayerState() override;
		virtual void Tick(float DeltaSeconds) override;
};
