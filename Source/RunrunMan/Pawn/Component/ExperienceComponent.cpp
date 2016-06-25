// Fill out your copyright notice in the Description page of Project Settings.

#include "RunrunMan.h"
#include "ExperienceComponent.h"


// Sets default values for this component's properties
UExperienceComponent::UExperienceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = false;
	PrimaryComponentTick.bCanEverTick = false;

	Experience = 0;
	Level = 1;
	MaxLevel = 10;
	DefaultValueExperence = 500;
	SetExperienceNextLevel();
	
	// ...
}



bool UExperienceComponent::CheckExperience()
{
	if (Experience >= ExperienceNextLevel)
	{
		int32 LLevel = Level;
		SetExperienceNextLevel();
		SetLevel(Level++);

		if (LLevel != Level)	return true;
	}
	return false;
}










/*

// Called when the game starts
void UExperienceComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UExperienceComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}
*/
