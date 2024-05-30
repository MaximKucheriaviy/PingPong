PhysicalBody ball(50, 50, 10, 10);

void Gamest() {
	nameSelector.disable();
	game.enable();
	app.addScreen(&game);
	game.addObject(&ball);
	ball.setTexture(&balltexture);
	ball.setXSpeed(1);
	ball.setYSpeed(1);
	ball.setColideBorder(true);
	ball.process();
	
}