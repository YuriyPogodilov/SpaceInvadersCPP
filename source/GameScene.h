#pragma once

#include "GameObject.h"
#include <vector>


class GameScene : public GameObject {
public:
	explicit GameScene(std::string_view data);

	void Init();
};
