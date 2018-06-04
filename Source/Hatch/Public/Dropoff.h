// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dropoff.generated.h"

class UStaticMeshComponent;
class USphereComponent;

UCLASS()
class HATCH_API ADropoff : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADropoff();

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MeshComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
};
