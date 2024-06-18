#include "GameScene.h"
#include <iostream>

GameScene::GameScene(std::string_view name) : GameObject(name) {
}

void GameScene::Init() {
	AddChild(std::make_shared<GameObject>("GameObject_1"));
	AddChild(std::make_shared<GameObject>("GameObject_2"));
	auto e = std::make_shared<GameObject>("GameObject_3");
	AddChild(e);
	e->AddChild(std::make_shared<GameObject>("GameObject_4"));
}
