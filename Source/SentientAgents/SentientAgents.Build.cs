// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SentientAgents : ModuleRules
{
	public SentientAgents(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"SentientAgents",
			"SentientAgents/Variant_Platforming",
			"SentientAgents/Variant_Platforming/Animation",
			"SentientAgents/Variant_Combat",
			"SentientAgents/Variant_Combat/AI",
			"SentientAgents/Variant_Combat/Animation",
			"SentientAgents/Variant_Combat/Gameplay",
			"SentientAgents/Variant_Combat/Interfaces",
			"SentientAgents/Variant_Combat/UI",
			"SentientAgents/Variant_SideScrolling",
			"SentientAgents/Variant_SideScrolling/AI",
			"SentientAgents/Variant_SideScrolling/Gameplay",
			"SentientAgents/Variant_SideScrolling/Interfaces",
			"SentientAgents/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
