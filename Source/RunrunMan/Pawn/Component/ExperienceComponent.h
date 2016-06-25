// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ExperienceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUNRUNMAN_API UExperienceComponent : public UActorComponent
{
	GENERATED_BODY()


private:

	/*����*/
	float Experience;
	/*���������� ����� �� ���������� �����*/
	float ExperienceNextLevel;
	/*��� �����*/
	float DefaultValueExperence;
	/*�������*/
	int32 Level;
	/*������������ �����*/
	

	/*******************************************/
	bool CheckExperience();

public:

	UExperienceComponent();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ParametersComponent)
		int32 MaxLevel;

	float GetExperience() { return Experience; }
	float GetExperienceNextLevel() { return ExperienceNextLevel; }
	int32 GetLevel() { return Level; }
	int32 GetMaxLevel() { return MaxLevel; }

	void SetExperience(float value) { Experience += value; Experience = FMath::Max(0.f, Experience);  CheckExperience(); }
	void SetLevel(float value) { if (value<=MaxLevel) Level = value; }
	void SetMaxLevel(float value) { MaxLevel = value; }
	void SetExperienceNextLevel() { ExperienceNextLevel = Level*DefaultValueExperence + ExperienceNextLevel; }
	



	// Called when the game starts
	//virtual void BeginPlay() override;
	
	// Called every frame
	//virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	
};
