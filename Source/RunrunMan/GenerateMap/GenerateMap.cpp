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
	sizeY = 40;

	ClearArrayMap();
	InitilizedArrayMap();
}

// Called when the game starts or when spawned
void AGenerateMap::BeginPlay()
{
	Super::BeginPlay();

	ClearArrayMap();
	InitilizedArrayMap();
	SpawnObjectSelectLine(5, OCube, 2, true);
	//SpaceFirstLine();
	
}

// Called every frame
void AGenerateMap::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FString FS = "";
	int32 MapSize = ArrayMap.Num();

	for (int i = sizeX -1; i>=0; i--)
	{
		for (int y = sizeY - 1; y >= 0; y--)
		{
			FS.Append(FString::Chr(ArrayMap[i + y + i*(sizeY-1)]));

			if (y == 0)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Green, FS);
				FS = "";
			}

		}

	}
	

	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Green, FString::FromInt(ArrayMap.Num() ));

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
	int32 MapSize = sizeX*sizeY;
	for (int32 i = 0; i<MapSize; i++)
	{

		ArrayMap.Add(ObjectType::Empty);

		//отрисовываем границы карты
		if (i == 0 || ((i + 1) % (MapSize / sizeX) == 0) || ((i) % (MapSize / sizeX) == 0))
		{
			ArrayMap[i] = ObjectType::DefaultCube;
		}

		if (i >= MapSize - sizeY && i<MapSize)
		{
			ArrayMap[i] = ObjectType::DefaultCube;
		}


	}


	SpawnObjectFirstLine(5, OClear, false);

	SpawnObjectSelectLine(1, OCube2, 3, true);
	SpawnObjectSelectLine(1, OCube, 2, true);
	SpawnObjectSelectLine(3, OCube3, 4, false);
	SpawnObjectSelectLine(7, OCube, 6, true);

	SpawnObjectFirstLine(5, OClear, false);

	SpawnObjectSelectLine(1, OCube2, 3, true);
	SpawnObjectSelectLine(1, OCube, 2, true);
	SpawnObjectSelectLine(3, OCube3, 4, false);
	SpawnObjectSelectLine(1, OCube, 6, true);

	SpawnObjectFirstLine(5, OClear, false);


	SpawnObjectSelectLine (30, OCube, 1, true);
	
	
}

bool AGenerateMap::CheckSpawnObject(int MapIndex, const sSpawnObject object, bool CollisionLine)
{
	
	int startObject = 0;
	int b = 0;
	//////////////////////////////////
	if (CollisionLine)
	{
		startObject = object.StartObject;
	}
	//////////////////////////////////


	for (int j = 0; j<object.x; j++)
	{

		for (int k = startObject; k<object.y; k++)
		{

			b = MapIndex - ((k - startObject)*sizeY);
			
			if (!(ArrayMap.IsValidIndex(b + j) )) return false;

			if (ArrayMap[b + j] != ObjectType::Empty)
			{
				return false;
			}





		}//break;

		 /***********************************************************/
	}
	return true;
}


void AGenerateMap::SpawnObjectSelectLine(int Replay, const sSpawnObject object, int StartLine, bool CollisionLine)
{
	int R = 0;
	bool isSpawn = true;
	int b = 0;
	int startObject = 0;
	int MapSize = ArrayMap.Num() - 1;

	if (CollisionLine)
	{
		startObject = object.StartObject;
	}

	
	/***********************количество повторов*/
	for (int i = 0; i<Replay; i++)
	{
		isSpawn = true;
		/***************идем по строчки и подбираем место для спауна обьекта*/
		for (int i = MapSize - sizeY*StartLine + 4; i<MapSize - sizeY; i++)
		{
			if (ArrayMap.IsValidIndex(i) && ArrayMap[i] == ObjectType::Empty&&isSpawn)
			{
				R = FMath::RandRange(0, 100);

				if (R >(100 - (LevelMap * 10)) && CheckSpawnObject(i, object, CollisionLine))
				{
					for (int j = 0; j<object.x; j++)
					{

						for (int k = startObject; k<object.y; k++)
						{

							b = i - ((k - startObject)*sizeY);

							ArrayMap[b + j] = object.CObject[j + k + (j*(object.y - 1))];






						}//break;

						 /***********************************************************/
					}
					isSpawn = false;

				}


			}


		}
	}
}



bool AGenerateMap::CheckEraseFirstLine(int MapIndex)
{
	if ((ArrayMap[MapIndex - 1] == ObjectType::Empty && ArrayMap[MapIndex - 2] == ObjectType::Empty))
		return false;

	if (ArrayMap[MapIndex + 1] == ObjectType::Empty && ArrayMap[MapIndex + 2] == ObjectType::Empty)
		return false;

	return true;
}

void AGenerateMap::SpawnObjectFirstLine(int Replay, const sSpawnObject object, bool CollisionLine)
{
	int R = 0;
	bool isSpawn = true;
	int b = 0;
	int startObject = 0;
	int MapSize = ArrayMap.Num() - 1;

	if (CollisionLine)
	{
		startObject = object.StartObject;
	}


	/***********************количество повторов*/
	for (int i = 0; i<Replay; i++)
	{
		isSpawn = true;
		
		/***************идем по строчки и подбираем место для спауна обьекта*/
		for (int i = MapSize - sizeY + 4; i<MapSize - 2; i++)
		{
			if (isSpawn && ArrayMap[i] != ObjectType::Empty)
			{

				R = FMath::RandRange(0, 100);

				if (R >= (100 - (LevelMap * 10)) && CheckEraseFirstLine(i))
				{
					for (int j = 0; j<object.x; j++)
					{

						for (int k = startObject; k<object.y; k++)
						{

							b = i - ((k - startObject)*sizeY);

							ArrayMap[b + j] = object.CObject[j + k + (j*(object.y - 1))];






						}//break;

						 /***********************************************************/

					}
					isSpawn = false;


				}
				//else 
				//{cout<<"sfsdf";}


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

