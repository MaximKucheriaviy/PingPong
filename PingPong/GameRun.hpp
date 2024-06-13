#include <iostream>
#include <cstdlib>
#include <ctime> 

PhysicalBody ball(50, 50, 376, 275);



int getRandomInt(int min, int max) {
	
	int result;

	srand(time(NULL));
	
	result = rand();
	while (result < min || result > max) {
		result = rand();
	}
	return result;
}

int getRandomitn(int min, int max) {
	int result;

	srand(time(NULL));

	result = rand() % 2;
	while (result < min || result > max) {
		cout << result << endl;
		result = rand() % 2;
	}
	if (result == 0) {
		result = 2;
	}
	
	return result;
}

float speedX = getRandomitn(0, 2);
float speedY = 1;
int rd = 0;
int rd2 = getRandomInt(1, 2);



void Gamest() {
	rd = getRandomInt(1, 2);
	speedY = getRandomitn(0, 2);
	
	games = true;
	nameSelector.disable();
	game.enable();
	app.addScreen(&game);
	game.addObject(&ball);
	ball.setTexture(&balltexture);
	ball.setColideBorder(true);

	cout << rd << endl;
	cout << rd2 << endl;
	cout << speedX << endl;
	cout << speedY << endl;
	
	if (rd == 1) {
		speedX *= 1;
		
	}
	else {
		speedX *= -1;
		
	}
	if (rd2 == 1) {
		
		speedY *= 1;
	}
	else {
		
		speedY *= -1;
	}
	
}
