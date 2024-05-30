#include "framework/SFMLFramework.hpp"
#include "GlobalDeclaration.hpp"
#include "MainMenu.hpp";
#include "PlayersNameSelector.hpp"
#include "GameRun.hpp"



int main() {
	arial.loadFromFile("./fonts/arial.ttf");
	balltexture.loadFromFile("./images/ballt.png");
	//mainMenurun();
	playersNameSelector();
	app.run();
}