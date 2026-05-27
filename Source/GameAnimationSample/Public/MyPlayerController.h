// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEANIMATIONSAMPLE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	UFUNCTION(Client, Reliable)
	void Client_SetInputEnabled(bool bEnabled);
	
	
};
