// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LO : ModuleRules
{
	public LO(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
		PublicDependencyModuleNames.Add("LOCharacter");
		//PrivateDependencyModuleNames.AddRange(new string[] { "LOCharacter" });

	}
}
