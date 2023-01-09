#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Map.h"
#include "Ghost.h"
//#include "Bonus.h"

class Bonus;

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
	void UpdateBonuses();
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
	void CreateBonus();

	GameState m_gameState = GameState::menu;
	sf::RenderWindow m_window;
	Pacman m_pacman;
	std::vector<Ghost> m_ghosts;
	std::vector<Map> m_maps;
	std::vector<Bonus*> m_bonuses;
	sf::Clock m_moveClock; // to do: refactoring
	sf::Clock m_bonusesClock;
	int m_mapNum = 0;
	bool m_running = true;
	bool m_changeMap = true;
	int m_score = 0;
};
