// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GenerateMapConstant.h"
#include "GenerateMap.generated.h"

const int32 RandomRangeValue = 3;

UCLASS()
class RUNRUNMAN_API AGenerateMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGenerateMap();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void GenerateMatrixMap();

	/*Размер динамического массива*/
	UPROPERTY(EditAnywhere, Category = GenerateMap)
	int32 sizeX;
	UPROPERTY(EditAnywhere, Category = GenerateMap)
	int32 sizeY;

	/*Динамический массив карты*/
	TArray <char> ArrayMap;

	UPROPERTY(EditAnywhere, Category = GenerateMap)
	int32 LevelMap = 1;

	

private:
	void ClearArrayMap();
	void InitilizedArrayMap();



	bool CheckEraseFirstLine(int MapIndex);
	void SpaceFirstLine();
	void SpaceFirstVar(int32 y, int32 var);
	bool CheckSpawnObject(int MapIndex, const sSpawnObject object, bool CollisionLine);
	void SpawnObjectSelectLine(int Replay, const sSpawnObject object, int StartLine, bool CollisionLine);
	void SpawnObjectFirstLine(int Replay, const sSpawnObject object, bool CollisionLine);
};
