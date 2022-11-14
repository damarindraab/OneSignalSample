// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "OneSignalSampleGameInstance.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPromptForPushNotifReceived, bool, bIsAccepted);

/**
 * 
 */
UCLASS()
class ONESIGNALSAMPLE_API UOneSignalSampleGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void OnStart() override;

	UFUNCTION(BlueprintCallable)
	virtual void InitializeOneSignal(const FString& AppID);

	UPROPERTY(BlueprintAssignable)
	FOnPromptForPushNotifReceived OnPromptForPushNotifReceived;
};
