#include "Game.h"

int main(int argc, char** argv) {
	Game game("SpaceInvadersCPP");

	game.Init();

	while (game.isRunning()) {
		game.Loop();
	}

	game.Shutdown();

	return 0;
}
