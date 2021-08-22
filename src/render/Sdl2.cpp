#include <stdexcept>
#include "Sdl2.hpp"

namespace yuzu
{
	Sdl2::~Sdl2() noexcept
	{
		if (_window != nullptr)
		{
			SDL_DestroyWindow(_window);
		}
		SDL_Quit();
	}

	void Sdl2::init(std::string windowName, int width, int height)
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			throw std::runtime_error("Could not initialize SDL2: " + std::string(SDL_GetError()));
		}
		_window = SDL_CreateWindow(
			windowName.c_str(),
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width, height,
			SDL_WINDOW_SHOWN
		);
		if (_window == nullptr) {
			throw std::runtime_error("Could create window: " + std::string(SDL_GetError()));
		}
	}

	void Sdl2::handleEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{ }
	}

	void Sdl2::render()
	{
		_screenSurface = SDL_GetWindowSurface(_window);
		SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));
		SDL_UpdateWindowSurface(_window);
	}
}