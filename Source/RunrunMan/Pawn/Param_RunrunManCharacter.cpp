// Fill out your copyright notice in the Description page of Project Settings.

#include "RunrunMan.h"
#include "Param_RunrunManCharacter.h"


AParam_RunrunManCharacter::AParam_RunrunManCharacter()
{
	ParamComponent = CreateDefaultSubobject<UParametersComponent>(TEXT("ParametersComponent"));
}

