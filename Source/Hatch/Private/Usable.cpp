// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Usable.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AUsable::AUsable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = StaticMeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	SphereComp->SetupAttachment(StaticMeshComp);

}

// Called when the game starts or when spawned
void AUsable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUsable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

