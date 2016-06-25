// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RunrunManCharacter.h"
#include "Pawn/Component/ExperienceComponent.h"
#include "Param_RunrunManCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RUNRUNMAN_API AParam_RunrunManCharacter : public ARunrunManCharacter
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ExperienceComponent, meta = (AllowPrivateAccess = "true"))
		UExperienceComponent *ExperienceComponent;

public:
	AParam_RunrunManCharacter();
	/*Возращаем компонент опыта*/
	FORCEINLINE class UExperienceComponent* GetExperienceComponent() const { return ExperienceComponent; }
	
	
};
