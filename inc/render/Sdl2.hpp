#pragma once

#include <SDL.h>
#undef main
#include <memory>
#include "IRender.hpp"

namespace yuzu
{
    class Sdl2 : public IRender
    {
    public:
        ~Sdl2() noexcept;
        void init(std::string windowName, int width, int height) override;
        void handleEvents() override;
        void render() override;

    private:
        SDL_Window* _window = nullptr;
        SDL_Surface* _screenSurface = nullptr;
    };
}