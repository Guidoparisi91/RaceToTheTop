// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameMode.h"
#include "GameFramework/PlayerController.h"
#include "GameAnimationSample/MainCharacter.h"
#include "MyGameState.h"
#include "MyPlayerController.h"

AMyGameMode::AMyGameMode()
{
	
}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(CountdownHandle, this, &AMyGameMode::OnMatchStart, ComienzoDePartida, false);
	GetWorldTimerManager().SetTimer(CountdownTick, this, &AMyGameMode::OnCountDownTick, 1.0f, true);

	AMyGameState* GS = GetGameState<AMyGameState>();
	if (GS)
		GS->Countdown = ComienzoDePartida;
	
}

void AMyGameMode::RestartPlayer(AController* NewPlayer)
{
	Super::RestartPlayer(NewPlayer);
	AMyPlayerController* MyPC = Cast<AMyPlayerController>(NewPlayer);
	if (MyPC)
		MyPC->Client_SetInputEnabled(false);
}


void AMyGameMode::OnMatchStart()
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		AMyPlayerController* MyPC = Cast<AMyPlayerController>(It->Get());
		if (MyPC)
			MyPC->Client_SetInputEnabled(true);
	}

	if (HasAuthority())
		StartMatch();
}

void AMyGameMode::OnCountDownTick()
{
	AMyGameState* GS= GetGameState<AMyGameState>();
	if (GS)
	{
		GS->Countdown -= 1;
		if (GS->Countdown <=0)
		{
			GetWorldTimerManager().ClearTimer(CountdownTick);
		}
	}
}
