Application app;
Screen mainMenu;
Screen nameSelector;
Screen game;

sf::Font arial;
sf::Texture balltexture;

enum Mode {
	singlePlayer,
	multiplayer
};

//Mode mode = Mode::singlePlayer;
Mode mode = Mode::multiplayer;

