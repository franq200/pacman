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
	void CreateMaps(const std::string& path);

	GameState m_gameState = GameState::menu;
	sf::RenderWindow m_window;
	Pacman m_pacman;
	std::vector<Map> m_map;
	sf::Clock m_moveClock;

	size_t m_currentMap = 0;
};
