#include "Game.h"
#include "Helper.h"
#include <filesystem>
#include <regex>
#include <string>
#include <iostream>

void Game::Init(std::string path)
{
	m_window.create(sf::VideoMode(size::windowSize, size::windowSize), "Pacman");

	CreateMaps(path);
	m_window.setFramerateLimit(60);
}

void Game::Run()
{
	if (m_gameState == GameState::menu)
	{
		TryChangeGameMode();
		TryChangeMap();
	}
	else
	{
		MakeMove();
	}

	MakeEventAction();
	Draw();
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
	m_maps[m_currentMap].Draw(m_window);
	m_window.display();
}

bool Game::IsRunning() const
{
	return m_running;
}

void Game::MakeMove()
{
	if (m_moveClock.getElapsedTime() > sf::milliseconds(speed::pacmanSpeed))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_pacman.MakeMove(Direction::up);
			m_moveClock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_pacman.MakeMove(Direction::right);
			m_moveClock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_pacman.MakeMove(Direction::left);
			m_moveClock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_pacman.MakeMove(Direction::down);
			m_moveClock.restart();
		}
	}
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
		if (m_mapNum == 0)
		{
			m_mapNum = static_cast<int>(m_maps.size());
		}
		else
		{
			m_mapNum--;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (m_mapNum == m_maps.size())
		{
			m_mapNum = 0;
		}
		else
		{
			m_mapNum++;
		}
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
				auto& newMap = m_maps.emplace_back();
				newMap.ReadMap(file.path().string());
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Error during process map with parent path " << mapsFolder << "." << e.what();
	}
}
