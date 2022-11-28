#include <SFML/Graphics.hpp>
#include <filesystem>
#include "game.h"

int main(int argc, char** argv)
{
    Game game;

    std::filesystem::path path(*argv);
    path = path.parent_path();
    path += "\\res\\maps";

    game.Init(path.string());
    return 0;
}