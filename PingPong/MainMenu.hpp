Button singlePlayerButton("Single Play", &arial, 20, 200, 100, 100, 50, sf::Color::Magenta);
Button multiPlayerButton("Co-op", &arial, 20, 200, 100, 500, 50, sf::Color::Blue);

void onSinglePlayerButtonPresss() {
	nameSelector.deleteObjects();
	mainMenu.disable();
	mode = singlePlayer;
	nameSelector.enable();
	initSelectScreen();
}

void onMultyPlayerButtonPresss() {
	nameSelector.deleteObjects();
	mainMenu.disable();
	mode = multiplayer;
	nameSelector.enable();
	initSelectScreen();
}

void mainMenurun() {
	singlePlayerButton.setCallback(onSinglePlayerButtonPresss);
	multiPlayerButton.setCallback(onMultyPlayerButtonPresss);
	mainMenu.addObject(&singlePlayerButton);
	mainMenu.addObject(&multiPlayerButton);
	app.addScreen(&mainMenu);
	mainMenu.enable();
}