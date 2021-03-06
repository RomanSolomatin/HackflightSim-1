/* 
   HackflightSim.Buils.cs: Build file file for HackflightSim

   Copyright (C) Simon D. Levy 2017

   This file is part of HackflightSim.

   HackflightSim is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   HackflightSim is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with HackflightSim.  If not, see <http://www.gnu.org/licenses/>.
 */

using UnrealBuildTool;
using System;


public class HackflightSim : ModuleRules
{
    public HackflightSim(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG" });

        // Un-comment and edit one of these lines to point to your Hackflight/src library
        //PrivateIncludePaths.Add("/home/slevy/Documents/Arduino/libraries/Hackflight/src");         // Linux
        PrivateIncludePaths.Add(Environment.GetEnvironmentVariable("userprofile") + "\\Documents\\Arduino\\libraries\\Hackflight\\src"); // Windows
    }
}
