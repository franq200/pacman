#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Map.h"
#include "Ghost.h"

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
	bool IsRunning() const;
private:
	void InitObjects();
	void MakeEventAction();
	void MakeMove();
	void TryChangeGameMode();
	void TryChangeMap();
	void LoadTextures();
	void CreateMaps(const std::string& path);

	GameState m_gameState = GameState::menu;
	sf::RenderWindow m_window;
	Pacman m_pacman;
	std::vector<Ghost> m_ghosts;
	std::vector<Map> m_maps;
	sf::Clock m_moveClock;
	int m_mapNum = 0;
	bool m_running = true;

	size_t m_currentMap = 0;
};
