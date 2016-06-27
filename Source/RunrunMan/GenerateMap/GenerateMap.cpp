// Fill out your copyright notice in the Description page of Project Settings.

#include "RunrunMan.h"
#include "GenerateMap.h"
#include "Engine.h"
#include "Pawn/Param_RunrunManCharacter.h"


// Sets default values
AGenerateMap::AGenerateMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sizeX = 10;
	sizeY = 10;

	ClearArrayMap();
	InitilizedArrayMap();
}

// Called when the game starts or when spawned
void AGenerateMap::BeginPlay()
{
	Super::BeginPlay();

	ClearArrayMap();
	InitilizedArrayMap();
	SpaceFirstLine();
	
}

// Called every frame
void AGenerateMap::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FString FS = "";

	for (int x = 0; x < ArrayMap.Num(); x++)
	{
			
			if (x%sizeY == 0 && x!=0)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Green, FS);
				FS = "";
				
			}
			
				FS.Append(FString::FromInt(ArrayMap[x]));
			
	}

	FS = "";
	for (int x = 0; x < ArrayMap.Num(); x++)
	{
		FS.Append(FString::FromInt(ArrayMap[x]));
	}

	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Green, FS);

}
void AGenerateMap::ClearArrayMap()
{
	for (int32 i = ArrayMap.Num()-1; i >=0; i--)
	{
		if (ArrayMap.IsValidIndex(i))
			ArrayMap.Remove(i);
	}

}

void AGenerateMap::InitilizedArrayMap()
{
	
	for (int32 x = 0; x < sizeX; x++)
		for (int32 y = 0; y < sizeY; y++)
		{
			if (y == 0 || y == sizeY-1)
			{
				ArrayMap.Add(1);
			}
			else
			{
				
				if (x%2 == 0)
				{
					ArrayMap.Add(1);
				}
				else
				{
					ArrayMap.Add(0);
				}
			}
		}
}
void AGenerateMap::SpaceFirstLine()
{
	int32 x = 0;

	if (sizeY > 3)
		for (int32 y = 2; y < sizeY-1; y++)
		{
			if (ArrayMap[y - 1] != 0 && ArrayMap[y - 2] != 0)
			{

				x = FMath::RandRange(0, sizeY - LevelMap);
				if (x <= sizeY / 10)
				{
					ArrayMap[y] = 0;
					
					SpaceFirstVar( y, FMath::RandRange(0, RandomRangeValue));
					
				}
			}
		}
}

void AGenerateMap::SpaceFirstVar(int32 y, int32 var)
{
	if (ArrayMap.IsValidIndex(y + sizeY))
	{ ArrayMap[y + sizeY] = 0; }

	if (ArrayMap.IsValidIndex(y + sizeY - 1)&&((var==0)||(var==1))&&(var !=0))
	{ ArrayMap[y + sizeY - 1] = 0; }

	if (ArrayMap.IsValidIndex(y + sizeY + 1) && ((var == 0) || (var == 2)) && (y + 1 < sizeY))
	{ ArrayMap[y + sizeY + 1] = 0; }

	if (ArrayMap.IsValidIndex(y + sizeY * 2))
	{ ArrayMap[y + sizeY * 2] = 0; }

	if (ArrayMap.IsValidIndex(y + sizeY * 2 - 1) && ((var == 0) || (var == 1)))
	{ ArrayMap[y + sizeY * 2 - 1] = 0; }

	if (ArrayMap.IsValidIndex(y + sizeY * 2 + 1) && ((var == 0) || (var == 2)) && (y + 1 < sizeY))
	{ ArrayMap[y + sizeY * 2 + 1] = 0; }
}
void AGenerateMap::GenerateMatrixMap()
{

	/*bool BSwapLine = false;
	int32 IGenerateValue = 0;

	for (int i = 0; i<10; i++)
		for (int j = 0; j < 10; j++)
		{
			ArrayMap[i][j] = 0;

			if (i == 0 || i == 9)
			{
				ArrayMap[i][j] = 1;
			}
			else
			{
				IGenerateValue = FMath::RandRange(0, 10);

				if (!(BSwapLine))
				{
					if (IGenerateValue>0)
						ArrayMap[i][j] = 1;

					if (IGenerateValue>=8)
						ArrayMap[i][j] = FMath::RandRange(0, 1);
					BSwapLine = true;
				}
				else
				{
					if (IGenerateValue==0)
						ArrayMap[i][j] = 1;

					if (IGenerateValue >= 8)
						ArrayMap[i][j] = FMath::RandRange(0, 1);

					BSwapLine = false;
				}
			}
		}*/
}

