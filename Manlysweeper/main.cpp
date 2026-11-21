#include <print>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "application.h"

#define MGL_IMPLEMENTATION
#include <mgl.h>

int main(int argc, char* argv[])
{
#ifndef NDEBUG
    try
    {
        bool sandboxModeEnabled = true;
    #else
        bool sandboxModeEnabled = false;
    #endif
        for (int i = 0; i < argc; ++i)
        {
            if (strcmp(argv[i], "--sandbox") == 0)
            {
                sandboxModeEnabled = true;
            }
        }

        Application app;
        app.Run(sandboxModeEnabled);
#ifndef NDEBUG
    }
    catch (const std::exception& e)
    {
        std::println(stderr, "Runtime Exception Encountered: {}", e.what());
        return -1;
    }
#endif
	return 0;
}
