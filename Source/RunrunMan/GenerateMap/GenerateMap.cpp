// Fill out your copyright notice in the Description page of Project Settings.

#include "RunrunMan.h"
#include "GenerateMap.h"
#include "Engine.h"


// Sets default values
AGenerateMap::AGenerateMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GenerateMatrixMap();
}

// Called when the game starts or when spawned
void AGenerateMap::BeginPlay()
{
	Super::BeginPlay();
	GenerateMatrixMap();
	
}

// Called every frame
void AGenerateMap::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FString FS = "";

	for (int j = 0; j < 10; j++)
		for (int i = 0; i < 10; i++)
		
		{
			FS.Append(FString::FromInt(ArrayMap[i][j]));
			if (i == 9)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, FS);
				FS = "";
			}
		}

}

void AGenerateMap::GenerateMatrixMap()
{

	bool BSwapLine = false;
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
		}
}

