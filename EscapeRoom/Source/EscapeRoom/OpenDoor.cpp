// Copyright Riho Hiiepuu 2017

#include "OpenDoor.h"
#include "Engine/World.h"
#include "Gameframework/Actor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner(); // get the owner

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}

// functionality to open a door
void UOpenDoor::OpenDoor()
{
	// set door rotation
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
}

// functionality to close a door
void UOpenDoor::CloseDoor()
{
	// set door rotation
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll trigger volume
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		// if ActorThatOpens is in the volume, open door
		OpenDoor();

		// get game time when the door was opened
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}

	//check if its time to close the door
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay) {
		CloseDoor();
	}
	
}

