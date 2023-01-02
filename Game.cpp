#include "Game.h"
#include "Helper.h"
#include <filesystem>
#include <regex>
#include <string>
#include <iostream>
#include <algorithm>

const std::string GameTitle = "Pacman";

void Game::Init(const std::string& path)
{
	m_window.create(sf::VideoMode(size::windowSize, size::windowSize), GameTitle);
	CreateMaps(path);
	LoadTextures();
	InitObjects();
	m_window.setFramerateLimit(60);
}

void Game::Run()
{
	switch (m_gameState)
	{
	case GameState::playing:
	{
		MakePacmanMove();
		MakeGhostsMove();
		if (IsPacmanCollisionWithGhost())
		{
			m_gameState = GameState::menu;
			Restart();
		}
		break;
	}
	case GameState::menu:
	{
		TryChangeGameMode();
		TryChangeMap();
		break;
	}
	}

	MakeEventAction();
	Draw();
}

void Game::InitObjects()
{
	m_pacman.Init(m_maps[m_mapNum].GetPacmanSpawn());
	InitGhosts();
}

void Game::InitGhosts()
{
	const std::vector<sf::Vector2f>& ghostsSpawns = m_maps[m_mapNum].GetGhostsSpawns();
	m_ghosts.resize(ghostsSpawns.size());
	for (int i = 0; i < ghostsSpawns.size(); ++i)
	{
		m_ghosts[i].Init(ghostsSpawns[i]);
	}
}

void Game::MakeEventAction()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			m_running = false;
		}
	}
}

void Game::Draw()
{
	m_window.clear();
	m_maps[m_mapNum].Draw(m_window);
	if (m_gameState == GameState::playing)
	{
		for (int i = 0; i < m_ghosts.size(); ++i)
		{
			m_window.draw(m_ghosts[i]);
		}
		m_window.draw(m_pacman);
	}
	m_window.display();
}

bool Game::IsRunning() const
{
	return m_running;
}

void Game::MakePacmanMove()
{
	if (m_moveClock.getElapsedTime() > sf::milliseconds(speed::pacmanSpeed))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (!IsPacmanCollision(Direction::up))
			{
				m_pacman.MakeMove(Direction::up);
				m_moveClock.restart();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (!IsPacmanCollision(Direction::right))
			{
				m_pacman.MakeMove(Direction::right);
				m_moveClock.restart();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (!IsPacmanCollision(Direction::left))
			{
				m_pacman.MakeMove(Direction::left);
				m_moveClock.restart();
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (!IsPacmanCollision(Direction::down))
			{
				m_pacman.MakeMove(Direction::down);
				m_moveClock.restart();
			}
		}
	}
}

void Game::MakeGhostsMove()
{
	for (auto& ghost : m_ghosts)
		ghost.MakeMove();
}

void Game::TryChangeGameMode()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		m_gameState = GameState::playing;
	}
}

void Game::TryChangeMap()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (m_changeMap == true)
		{
			if (m_mapNum == 0)
			{
				m_mapNum = static_cast<int>(m_maps.size() - 1);
			}
			else
			{
				m_mapNum--;
			}
			m_changeMap = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_changeMap == true)
		{
			if (m_mapNum == m_maps.size() - 1)
			{
				m_mapNum = 0;
			}
			else
			{
				m_mapNum++;
			}
			m_changeMap = false;
		}
	}
	else
	{
		m_changeMap = true;
	}
}

void Game::LoadTextures()
{
	textures::ghostTexture.loadFromFile("ghost.png");
	textures::pacmanTexture.loadFromFile("pacman.png");
}

void Game::CreateMaps(const std::string& path)
{
	std::filesystem::path mapsFolder(path);

	try
	{
		for (auto const& file : std::filesystem::directory_iterator{ mapsFolder })
		{
			auto fileName = file.path().filename();
			std::regex regex("^map(\\d)+.txt$");
			if (std::regex_search(fileName.string(), regex))
			{
				Map newMap;
				if (newMap.ReadAndValidateMap(file.path().string()))
				{
					m_maps.push_back(newMap);
				}
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Error during process map with parent path " << mapsFolder << "." << e.what();
	}
}

bool Game::IsPacmanCollision(Direction direction) const
{
	if (direction == Direction::up)
	{
		sf::Vector2f pacmanNextPos = { m_pacman.getPosition().x, m_pacman.getPosition().y - size::cellSize };
		if (pacmanNextPos.y < 0)
		{
			return true;
		}
		std::pair<std::size_t, std::size_t> indexPacmanPos = position::GetMapIndexesFromPosition(pacmanNextPos);
		return m_maps[m_mapNum].IsBlockedCell(indexPacmanPos.first, indexPacmanPos.second);
	}
	else if (direction == Direction::down)
	{
		sf::Vector2f pacmanNextPos = { m_pacman.getPosition().x, m_pacman.getPosition().y + size::cellSize };
		if (pacmanNextPos.y > size::windowSize - size::cellSize)
		{
			return true;
		}
		std::pair<std::size_t, std::size_t> indexPacmanPos = position::GetMapIndexesFromPosition(pacmanNextPos);
		return m_maps[m_mapNum].IsBlockedCell(indexPacmanPos.first, indexPacmanPos.second);
	}
	else if (direction == Direction::right)
	{
		sf::Vector2f pacmanNextPos = { m_pacman.getPosition().x + size::cellSize, m_pacman.getPosition().y };
		if (pacmanNextPos.x > size::windowSize - size::cellSize)
		{
			return true;
		}
		std::pair<std::size_t, std::size_t> indexPacmanPos = position::GetMapIndexesFromPosition(pacmanNextPos);
		return m_maps[m_mapNum].IsBlockedCell(indexPacmanPos.first, indexPacmanPos.second);
	}
	else if (direction == Direction::left)
	{
		sf::Vector2f pacmanNextPos = { m_pacman.getPosition().x - size::cellSize, m_pacman.getPosition().y };
		if (pacmanNextPos.x < 0)
		{
			return true;
		}
		std::pair<std::size_t, std::size_t> indexPacmanPos = position::GetMapIndexesFromPosition(pacmanNextPos);
		return m_maps[m_mapNum].IsBlockedCell(indexPacmanPos.first, indexPacmanPos.second);
	}
	return false;
}

bool Game::IsPacmanCollisionWithGhost() const
{
	sf::Vector2f pacmanPos = m_pacman.getPosition();
	return std::any_of(m_ghosts.begin(), m_ghosts.end(), [pacmanPos](const auto& ghost) {return ghost.getPosition() == pacmanPos; });
}

void Game::Restart()
{
	m_pacman.setPosition(m_maps[m_mapNum].GetPacmanSpawn());
	std::vector<sf::Vector2f> ghostsSpawns = m_maps[m_mapNum].GetGhostsSpawns();
	for (int i = 0; i < m_ghosts.size(); ++i)
	{
		m_ghosts[i].setPosition(ghostsSpawns[i]);
	}
}
