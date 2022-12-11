// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/GASInputConfig.h"

const UInputAction* UGASInputConfig::FindNativeInputActionForTag(const FGameplayTag& InputTag) const
{
	for (const FGASInputAction& Action : NativeInputActions)
	{
		if (Action.InputAction && (Action.InputTag == InputTag))
		{
			return Action.InputAction;
		}
	}

	return nullptr;
}

const UInputAction* UGASInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag) const
{
	for (const FGASInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && (Action.InputTag == InputTag))
		{
			return Action.InputAction;
		}
	}

	return nullptr;
}
