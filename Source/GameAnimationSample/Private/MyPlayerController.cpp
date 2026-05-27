// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"


void AMyPlayerController::Client_SetInputEnabled_Implementation(bool bEnabled)
{
	if (!GetPawn()) return;
	
	if (bEnabled)
		{
			GetPawn()->EnableInput(this);
		}
	else
	
		GetPawn()->DisableInput(this);

	
	}
