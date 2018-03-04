// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactor.h"


// Sets default values for this component's properties
UInteractor::UInteractor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    UWorld* world = GetOwner()->GetWorld();
    FVector start = GetOwner()->GetTransform().GetLocation();
    FVector point = world->GetFirstPlayerController()->GetControlRotation().Vector();
    
    
    FVector end = start + point * LineLength;
    //DrawDebugLine(world, start, end, FColor(0,255,0), false, 0.f, 0, 8.f );
    FHitResult result;
    FCollisionObjectQueryParams q(ECollisionChannel::ECC_WorldStatic);
    world->LineTraceSingleByObjectType(result, start, end,q);
    
    //FString p = point.ToString();
    if (result.GetActor() && result.GetActor()->GetName()=="SM_MatPreviewMesh_02_2")
    {
        
        UE_LOG(LogTemp, Warning, TEXT("point to : %s"), *result.GetActor()->GetName());
    }
//    bool LineTraceSingleByObjectType
//    (
//     struct FHitResult & OutHit,
//     const FVector & Start,
//     const FVector & End,
//     const FCollisionObjectQueryParams & ObjectQueryParams,
//     const FCollisionQueryParams & Params
//     )
	// ...
}

