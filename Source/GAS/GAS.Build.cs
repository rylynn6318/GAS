// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAS : ModuleRules
{
    public GAS(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks", "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

        PrivateIncludePaths.Add("GAS");
    }
}
