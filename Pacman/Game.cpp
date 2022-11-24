#include "Game.h"
#include "Helper.h"

void Game::Init(std::string path)
{
	m_window.create(sf::VideoMode(size::windowSize, size::windowSize), "Pacman");
}

void Game::Run()
{
	if (m_gameState == GameState::menu)
	{
		TryChangeGameMode();
	}
	else
	{
		MakeMove();
	}
	Draw();
}

void Game::Draw()
{
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

void Game::LoadTextures()
{
	textures::ghostTexture.loadFromFile("ghost.png");
	textures::pacmanTexture.loadFromFile("pacman.png");
}
