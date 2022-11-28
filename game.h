#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Map.h"

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
	Map m_map;
	sf::Clock m_moveClock;
};
