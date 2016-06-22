// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RunrunManCharacter.h"
#include "Component/ParametersComponent.h"
#include "Param_RunrunManCharacter.generated.h"

/**
 * 
 */
UCLASS()
class RUNRUNMAN_API AParam_RunrunManCharacter : public ARunrunManCharacter
{
	GENERATED_BODY()

public:
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = HeroParameters, meta = (AllowPrivateAccess = "true"))
		class UParametersComponent *ParamComponent;

		AParam_RunrunManCharacter();
	
	
};
