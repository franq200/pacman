#include <SFML/Graphics.hpp>
#include <string>
#include "Pacman.h"

enum class GameState
{
	playing = 0,
	menu
};

class Game
{
public:
	void Init(std::string path);
	void Run();
	void Draw();
private:
	void MakeMove();
	void TryChangeGameMode();
	void LoadTextures();

	GameState m_gameState = GameState::menu;
	sf::RenderWindow m_window;
	Pacman m_pacman;
	sf::Clock m_moveClock;
};
