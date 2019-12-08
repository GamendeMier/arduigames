#pragma once

enum class Direction {
    Up, Down, Left, Right
};

template<class T>
struct Vec2 {
    T x;
    T y;
};
