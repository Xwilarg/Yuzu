#pragma once

#include <string>

namespace yuzu
{
    class IRender
    {
    public:
        virtual void init(std::string windowName, int width, int height) = 0;
        virtual void handleEvents() = 0;
        virtual void render() = 0;
    };
}