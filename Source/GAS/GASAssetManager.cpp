#include "GASAssetManager.h"
#include "GASGameplayTags.h"

UGASAssetManager& UGASAssetManager::Get()
{
	check(GEngine);

	UGASAssetManager* MyAssetManager = Cast<UGASAssetManager>(GEngine->AssetManager);
	return *MyAssetManager;
}

void UGASAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FGASGameplayTags::InitializeNativeTags();
}
