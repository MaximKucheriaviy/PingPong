Button singlePlayerButton("Single Play", new sf::Font(), 10, 200, 100, 100, 30);
Button multiPlayerButton("Co-op", new sf::Font(), 10, 200, 100, 100, 50, sf::Color::Blue);
void mainMenurun() {
	mainMenu.addObject(&singlePlayerButton);
	mainMenu.addObject(&multiPlayerButton);
	app.addScreen(&mainMenu);
	mainMenu.enable();
}