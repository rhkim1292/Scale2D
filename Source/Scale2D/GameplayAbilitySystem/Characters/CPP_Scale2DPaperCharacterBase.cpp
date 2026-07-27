// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Scale2DPaperCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/PrimitiveComponent.h"

ACPP_Scale2DPaperCharacterBase::ACPP_Scale2DPaperCharacterBase()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //Create Ability System Component
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(ASCReplicationMode);

    // Set size for collision capsule
    GetCapsuleComponent()->InitCapsuleSize(114.978203f, 147.019058f);

    if (UCharacterMovementComponent* MovementComp = GetCharacterMovement())
    {
        MovementComp->GravityScale = 3.0f;
        MovementComp->bUseFlatBaseForFloorChecks = true;
        MovementComp->bConstrainToPlane = true;
        MovementComp->SetPlaneConstraintNormal(FVector(0.0f, 1.0f, 0.0f));
        MovementComp->JumpZVelocity = 1000.0f;
        MovementComp->AirControl = 0.7f;
    }
}

void ACPP_Scale2DPaperCharacterBase::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }
}

void ACPP_Scale2DPaperCharacterBase::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();

    if (AbilitySystemComponent)
    {
        AbilitySystemComponent->InitAbilityActorInfo(this, this);
    }
}

void ACPP_Scale2DPaperCharacterBase::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (UPaperFlipbookComponent* Flipbook = GetSprite())
    {
        // Lower Z (further "back"/lower on screen) should draw in front,
        // so invert Z into the priority.
        const int32 NewSortPriority = FMath::RoundToInt(-GetActorLocation().Z);
        Flipbook->SetTranslucentSortPriority(NewSortPriority);
    }
}

UAbilitySystemComponent* ACPP_Scale2DPaperCharacterBase::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}