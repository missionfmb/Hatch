// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/Dropoff.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/World.h"
#include "Engine.h"
#include "HatchCharacter.h"

// Sets default values
ADropoff::ADropoff()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(MeshComp);

}

// Called when the game starts or when spawned
void ADropoff::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADropoff::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADropoff::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);



	AHatchCharacter* Character = Cast<AHatchCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());


	if (Character->bHasUsable)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dropped Off Usable!"));
		Character->UsableInGame->SetActorHiddenInGame(false);
		Character->bHasUsable = false;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Need to get usable!"));
	}

	

	
}

