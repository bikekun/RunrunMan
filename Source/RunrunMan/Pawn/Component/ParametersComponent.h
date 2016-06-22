// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ParametersComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNRUNMAN_API UParametersComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UParametersComponent();

	

	void	ChangeHealth(float value);
	bool	CheckHealth();

	void	SetMaxHealth(float value)		{ MaxHealth = value; }
	void	SetSpeedMoved(float value)		{ SpeedMoved = value; }
	void	SetLevel()						{ LevelCharacter++; }
	
	float	GetSpeedMoved()					{ return SpeedMoved; }
	int32	GetLevel()						{ return LevelCharacter; }
	int32	GetHealth()						{ return Health; }
	int32	GetMaxHealth()					{ return MaxHealth; }

	int32 DefaultMaxHealth;

private:

	int32 Health;
	int32 MaxHealth;

	float SpeedMoved;

	int32 LevelCharacter;



	// Called when the game starts
	//virtual void BeginPlay() override;
	
	// Called every frame
	//virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
