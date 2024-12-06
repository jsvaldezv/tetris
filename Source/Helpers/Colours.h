#pragma once
#include <raylib.h>
#include <vector>

namespace Colours
{
    static constexpr Color DarkBlue = { 44, 44, 127, 255 };
    static constexpr Color DarkGrey = { 26, 31, 40, 255 };
    static constexpr Color Green = { 47, 230, 23, 255 };
    static constexpr Color Red = { 232, 18, 18, 255 };
    static constexpr Color Orange = { 226, 116, 17, 255 };
    static constexpr Color Yellow = { 237, 234, 4, 255 };
    static constexpr Color Purple = { 166, 0, 247, 255 };
    static constexpr Color Cyan = { 21, 204, 209, 255 };
    static constexpr Color Blue = { 13, 64, 216, 255 };
    static constexpr Color LightBlue = { 59, 85, 162, 255 };

    static std::vector<Color> getCellColours()
    {
        return { DarkGrey, Green, Red, Orange, Yellow, Purple, Cyan, Blue };
    }
}
