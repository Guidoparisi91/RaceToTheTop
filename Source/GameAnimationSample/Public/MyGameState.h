// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MyGameState.generated.h"

/**
 * 
 */
UCLASS()
class GAMEANIMATIONSAMPLE_API AMyGameState : public AGameState
{
	GENERATED_BODY()


public:

	UPROPERTY(ReplicatedUsing=OnRep_Countdown, BlueprintReadOnly)
	int32 Countdown;

	UPROPERTY(Replicated)
	bool bMatchInProgress;

	UFUNCTION()
	void OnRep_Countdown();


	
};

