#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Map.h"
#include "Ghost.h"

enum class GameState : std::uint8_t
{
	playing = 0,
	menu
};

class Game
{
public:
	void Init(const std::string& path);
	void Run();
	void Draw();
	bool IsRunning() const;
private:
	void Restart();
	void InitObjects();
	void InitGhosts();
	void CreateMaps(const std::string& path);
	void LoadTextures();
	void MakePacmanMove();
	void MakeGhostsMove();
	void TryChangeMap();
	void TryChangeGameMode();
	void MakeEventAction();
	bool IsPacmanCollision(Direction) const;
	bool IsPacmanCollisionWithGhost() const;

	GameState m_gameState = GameState::menu;
	sf::RenderWindow m_window;
	Pacman m_pacman;
	std::vector<Ghost> m_ghosts;
	std::vector<Map> m_maps;
	sf::Clock m_moveClock; // to do: refactoring
	int m_mapNum = 0;
	bool m_running = true;
	bool m_changeMap = true;
};
