/*
   HackflihtSimBoard.hpp: Hackflight SimBoard class implementation for Unreal Engine

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
   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <hackflight.hpp>
#include <boards/sim/sim.hpp>

#include "Engine/Engine.h"


#ifdef _WIN32
void hf::SimBoard::cputime(struct timespec *tv)
{
    static time_t startsec;

    int retval = timespec_get(tv, TIME_UTC);

    if (startsec == 0) {
        startsec = tv->tv_sec;
    }

    tv->tv_sec -= startsec;
}

#else

#include <stdio.h>

void hf::SimBoard::cputime(struct timespec * tv)
{
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, tv);
}

#endif

void hf::Board::outbuf(char * buf)
{
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(0, 15.0f, FColor::Yellow, FString(buf));
	}

}


