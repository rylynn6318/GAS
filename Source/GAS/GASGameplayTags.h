#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct GAS_API FGASGameplayTags
{
public:
	static const FGASGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeTags();

	FGameplayTag InputTag_Move;
	FGameplayTag InputTag_Look_Mouse;
	FGameplayTag InputTag_Sprint;
	FGameplayTag InputTag_Dodge;
	FGameplayTag InputTag_Jump;

protected:
	void AddAllTags(class UGameplayTagsManager& Manager);
	void AddTag(FGameplayTag& /*out*/ Tag, const ANSICHAR* TagName, const ANSICHAR* TagComment);

private:
	static FGASGameplayTags GameplayTags;
};
