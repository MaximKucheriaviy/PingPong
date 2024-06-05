#include "framework/SFMLFramework.hpp"
#include "GlobalDeclaration.hpp"
#include "MainMenu.hpp";
#include "GameRun.hpp"
#include "PlayersNameSelector.hpp"

void ballback() {
	if (games) {
		ballclock.restart();
		games = false;
	}
	if (ballclock.getElapsedTime().asSeconds() > 3 and ballclock.getElapsedTime().asSeconds() < 4) {
		ball.setXSpeed(speedX);
		ball.setYSpeed(speedY);
		ball.process();
		return;
	
	}

}

Process ballstop(10, &ballback);


int main() {
	arial.loadFromFile("./fonts/arial.ttf");
	balltexture.loadFromFile("./images/ballt.png");
	//mainMenurun();
	playersNameSelector();
	game.setProcess(&ballstop);
	app.run();
}