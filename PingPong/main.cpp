#include "framework/SFMLFramework.hpp"
#include <random>
#include <time.h>
#include "GlobalDeclaration.hpp"
#include "ResultScreen.hpp"
#include "GameRun.hpp"
#include "PlayersNameSelector.hpp"
#include "MainMenu.hpp";





int main() {
	srand(time(NULL));
	arial.loadFromFile("./fonts/arial.ttf");
	balltexture.loadFromFile("./images/ballt.png");
	mainMenurun();
	playersNameSelector();
	gameScreenInit();
	resultScreenSetup();
	

	app.run();
}