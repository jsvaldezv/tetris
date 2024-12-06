#pragma once
#include <raylib.h>

inline double lastUpdateTime { 0 };

inline static bool eventTriggered (double interval)
{
    double currentTime = GetTime();

    if ((currentTime - lastUpdateTime) >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}
