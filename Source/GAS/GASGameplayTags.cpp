#include "GASGameplayTags.h"
#include "GameplayTagsManager.h"

FGASGameplayTags FGASGameplayTags::GameplayTags;

void FGASGameplayTags::InitializeNativeTags()
{
	UGameplayTagsManager& GameplayTagsManager = UGameplayTagsManager::Get();

	GameplayTags.AddAllTags(GameplayTagsManager);

	GameplayTagsManager.DoneAddingNativeTags();
}

void FGASGameplayTags::AddAllTags(UGameplayTagsManager& Manager)
{
	AddTag(InputTag_Move, "InputTag.Move", "Move input");
	AddTag(InputTag_Look_Mouse, "InputTag.LookMouse", "Look Mouse input");
	AddTag(InputTag_Sprint, "InputTag.Sprint", "Sprint input");
	AddTag(InputTag_Dodge, "InputTag.Dodge", "Dodge input");
	AddTag(InputTag_Jump, "InputTag.Jump", "Jump input");
}

void FGASGameplayTags::AddTag(FGameplayTag& Tag, const ANSICHAR* TagName, const ANSICHAR* TagComment)
{
	Tag = UGameplayTagsManager::Get().AddNativeGameplayTag(FName(TagName), FString(TEXT("(Native) ")) + FString(TagComment));
}
