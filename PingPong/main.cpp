#include "framework/SFMLFramework.hpp"
#include "GlobalDeclaration.hpp"
#include "MainMenu.hpp";
#include "PlayersNameSelector.hpp"



int main() {
	arial.loadFromFile("./fonts/arial.ttf");
	mainMenurun();
	playersNameSelector();
	app.run();
}