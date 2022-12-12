#include <SFML/Graphics.hpp>
#include <filesystem>
#include "game.h"

std::string CreateBasePath(char** argv)
{
    std::filesystem::path path(*argv);
    path = path.parent_path();
    path += "\\res\\maps";
    return path.string();
}

int main(int argc, char** argv)
{
    Game game;
  
    game.Init(CreateBasePath(argv));
    while (game.IsRunning())
    {
        game.Run();
    }
    return 0;
}