// Fill out your copyright notice in the Description page of Project Settings.


#include "OneSignalSampleGameInstance.h"

#include "OneSignal/OneSignalLibrary.h"

void UOneSignalSampleGameInstance::OnStart()
{
	Super::OnStart();
}

void UOneSignalSampleGameInstance::InitializeOneSignal(const FString& AppID)
{
	// sample app id= 7849aa3a-c8ee-4efd-ab9e-93b101252d05
	UOneSignalLibrary::SetAppID(AppID);
	UOneSignalLibrary::Initialize();
	// Request permission for mobile device to receive notification
	UOneSignalLibrary::PromptForPushNotifications(FOneSignalUserResponseCallback::CreateLambda([this](bool bAccepted)
	{
		OnPromptForPushNotifReceived.Broadcast(bAccepted);
	}));
	
}
