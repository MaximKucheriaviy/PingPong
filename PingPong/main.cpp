#include "framework/SFMLFramework.hpp"
#include "GlobalDeclaration.hpp"
#include "MainMenu.hpp";
#include "GameRun.hpp"
#include "PlayersNameSelector.hpp"




int main() {
	arial.loadFromFile("./fonts/arial.ttf");
	balltexture.loadFromFile("./images/ballt.png");
	//mainMenurun();
	playersNameSelector();
	app.run();
}