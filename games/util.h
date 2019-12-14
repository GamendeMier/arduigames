#pragma once

enum class Direction {
    Up, Down, Left, Right
};

template<typename T>
struct Vec2 {
    T x;
    T y;
};
