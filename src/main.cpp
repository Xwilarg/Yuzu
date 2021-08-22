#include <stdexcept>

#ifdef RENDER_SDL2
	#include "Sdl2.hpp"
#endif

#include <iostream>

int main()
{
#ifdef RENDER_SDL2
	auto renderer = std::make_unique<yuzu::Sdl2>();
#else
	throw std::logic_error("No rendering method defined");
#endif

	renderer->init("Yuzu", 500, 300);

	while (true)
	{
		renderer->handleEvents();
		renderer->render();
	}
}