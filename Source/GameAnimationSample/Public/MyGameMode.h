// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */


UCLASS()
class GAMEANIMATIONSAMPLE_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	virtual void RestartPlayer(AController* NewPlayer) override;
	
private:
	
	FTimerHandle CountdownHandle;
	FTimerHandle CountdownTick;

	void OnMatchStart();
	void OnCountDownTick();
	

	
public:
	
	
	AMyGameMode();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ComienzoDePartida = 3;

	
	
	
	
};


