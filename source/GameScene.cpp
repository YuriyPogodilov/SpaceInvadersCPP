#include "GameScene.h"
#include "SpaceShip.h"
#include <iostream>

GameScene::GameScene(std::string_view name) : GameObject(name) {
}

void GameScene::Init() {
	// Player
	auto spaceShip = std::make_shared<SpaceShip>();
	AddChild(spaceShip);
	spaceShip->SetPosition({500.f, 500.f});

	// Enemies
	// TODO: add enemies
}
