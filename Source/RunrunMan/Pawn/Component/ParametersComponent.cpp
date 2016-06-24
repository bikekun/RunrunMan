// Fill out your copyright notice in the Description page of Project Settings.

#include "RunrunMan.h"
#include "ParametersComponent.h"


// Sets default values for this component's properties
UParametersComponent::UParametersComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = false;
	PrimaryComponentTick.bCanEverTick = false;


	DefaultMaxHealth = 100;
	Health = DefaultMaxHealth;
	MaxHealth = DefaultMaxHealth;

	SpeedMoved = 1.0f;

	LevelCharacter = 1;
	// ...
}


void	UParametersComponent::ChangeHealth(float value)
{
	Health += value;
	Health = FMath::Min(Health, MaxHealth);
	Health = FMath::Max(0, Health);

	if (!(CheckHealth()))
	{
		//диспатч
		DDeath.Broadcast();
	}
}

bool	UParametersComponent::CheckHealth()
{
	if (Health <= 0)
	{
		return false;
	}
	return true;
}























//// Called when the game starts
//void UParametersComponent::BeginPlay()
//{
//	Super::BeginPlay();
//
//	// ...
//	
//}
//
//
//// Called every frame
//void UParametersComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
//{
//	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
//
//	// ...
//}

