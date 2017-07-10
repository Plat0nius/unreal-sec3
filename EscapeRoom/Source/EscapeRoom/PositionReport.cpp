// Copyright Riho Hiiepuu 2017

#include "PositionReport.h"
#include "Gameframework/Actor.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	FString ObjName = "";
	FString ObjPos = GetOwner()->GetActorLocation().ToString();

	ObjName =  GetOwner()->GetName();

	UE_LOG(LogTemp, Warning, TEXT("%s is at %s"), *ObjName, *ObjPos);
	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

