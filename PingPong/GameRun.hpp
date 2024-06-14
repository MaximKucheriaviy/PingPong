#include <iostream>

PhysicalBody ball(30, 30, app.getWindow()->getSize().x / 2 - 15, app.getWindow()->getSize().y / 2 - 15);
PhysicalBody platform1(10, 100, 50, app.getWindow()->getSize().y / 2 - 50, sf::Color::Yellow);
PhysicalBody platform2(10, 100, app.getWindow()->getSize().x - 60, app.getWindow()->getSize().y / 2 - 50, sf::Color::Cyan);
Box loozeZoneLeft(40, app.getWindow()->getSize().y, 0, 0, sf::Color::Transparent);
Box loozeZoneRight(40, app.getWindow()->getSize().y, app.getWindow()->getSize().x - 40, 0, sf::Color::Transparent);

void platformControll() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		platform1.setYSpeed(platformSpeed * -1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		platform1.setYSpeed(platformSpeed);
	}
	else {
		platform1.setYSpeed(0);
	}

	if (mode != singlePlayer) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			platform2.setYSpeed(platformSpeed * -1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			platform2.setYSpeed(platformSpeed);
		}
		else {
			platform2.setYSpeed(0);
		}
	}
	
}

void onBallToush(PhysicalBody* platform, int xMult = 1) {
	ball.setXSpeed(ballSpeed);
	sf::FloatRect ballRect = ball.getBounds();
	sf::FloatRect platformRect = platform->getBounds();
	int touchPoint = ballRect.top + (ballRect.height / 2) - platformRect.top;
	int gap = platformRect.height / 5;
	if (touchPoint < gap) {
		int angle = 45;
		ball.setXSpeed(ballSpeed * sin(angle) * xMult);
		ball.setYSpeed(ballSpeed * cos(angle) * -1);
	}
	else if (touchPoint >= gap && touchPoint < gap * 2) {
		int angle = 20;
		ball.setXSpeed(ballSpeed * sin(angle) * xMult);
		ball.setYSpeed(ballSpeed * cos(angle) * -1);
	}
	else if (touchPoint >= gap * 2 && touchPoint < gap * 3) {
		ball.setXSpeed(ballSpeed * xMult);
		ball.setYSpeed(0);
	}
	else if (touchPoint >= gap * 3 && touchPoint < gap * 4) {
		int angle = 20;
		ball.setXSpeed(ballSpeed * sin(angle) * xMult);
		ball.setYSpeed(ballSpeed * cos(angle));
	}
	else if (touchPoint >= gap * 4) {
		int angle = 45;
		ball.setXSpeed(ballSpeed * sin(angle) * xMult);
		ball.setYSpeed(ballSpeed * cos(angle));
	}
	touches++;
	if (touches > 5) {
		ballSpeed++;
		touches = 0;
	}
}

void platformColide() {
	if (ball.collide(&platform1)) {
		onBallToush(&platform1);
	}
	if (ball.collide(&platform2)) {
		onBallToush(&platform2, -1);
	}
	
}

void loseZoneTouch() {
	if (ball.getBounds().intersects(loozeZoneLeft.getBounds())) {
		game.disable();
		resultsScreen.enable();
		setupResultScreen(Player2.getLine());
	}
	else if (ball.getBounds().intersects(loozeZoneRight.getBounds())) {
		game.disable();
		resultsScreen.enable();
		setupResultScreen(Player1.getLine());
	}
}



void aiRun() {
	if (mode != singlePlayer) {
		return;
	}
	sf::FloatRect ballRect = ball.getBounds();
	sf::FloatRect platformRect = platform2.getBounds();
	if (ballRect.top + (ballRect.height / 2) < platformRect.top +(platformRect.height / 2)) {
		platform2.setYSpeed(platformSpeed * -1);
	}
	else if (ballRect.top + (ballRect.height / 2) > platformRect.top + (platformRect.height / 2)) {
		platform2.setYSpeed(platformSpeed);
	}
	else {
		platform2.setYSpeed(0);
	}

}

Process platformControlProcess(10, platformControll);
Process platformColideProcess(5, platformColide);
Process loseZoneTouchProcess(5, loseZoneTouch);
Process aiRunProcess(1, aiRun);


int getRandomInt(int min, int max) {
	
	int result;

	
	result = rand();
	while (result < min || result > max) {
		result = rand();
	}
	return result;
}




void gameScreenInit() {
	ball.setTexture(&balltexture);
	ball.setColideBorder(true);
	game.addObject(&ball);
	game.addObject(&platform1);
	game.addObject(&platform2);
	game.addObject(&loozeZoneLeft);
	game.addObject(&loozeZoneRight);
	game.setProcess(&platformControlProcess);
	game.setProcess(&platformColideProcess);
	game.setProcess(&loseZoneTouchProcess);
	game.setProcess(&aiRunProcess);

	app.addScreen(&game);

}



void setBallSpeed() {
	bool direction = getRandomInt(1, 10) > 5;
	if (direction) {
		ball.setXSpeed(ballSpeed);
	}
	else {
		ball.setXSpeed(ballSpeed * -1);
	}
}

void Gamest() {
	ball.setPosition(app.getWindow()->getSize().x / 2 - 15, app.getWindow()->getSize().y / 2 - 15);
	ball.setXSpeed(0);
	ball.setYSpeed(0);

	nameSelector.disable();
	game.setTimout(Timeout(setBallSpeed, 2000));
	ballSpeed = 2;
	touches = 0;
	game.enable();
	
	
}
