// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WheeledVehicleObject.h"
#include "VehicleSpawner.generated.h"

UCLASS()
class SUMOTOUNREAL_API AVehicleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehicleSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWheeledVehicleObject> ToSpawn;

	UPROPERTY(EditAnywhere)
	TArray<int> SpawningSplineID;

	UPROPERTY(EditAnywhere)
	float SpawnTickTime;


	TArray<AActor*> SplineActors;
	TArray<AWayPoint*> Waypoints;
	float temp = 0;
	int spawning = 0;

	UFUNCTION()
	AWheeledVehicleObject* Spawn(FVector Location, AWayPoint* WayPoint);

	UFUNCTION()
	TArray<AActor*> FindAllWaypoint();

	UFUNCTION()
	void PrintLog(FString Text);



};