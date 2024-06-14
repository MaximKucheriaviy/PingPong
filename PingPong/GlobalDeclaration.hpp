Application app;
Screen mainMenu;
Screen nameSelector;
Screen game;
Screen resultsScreen;

sf::Font arial;
sf::Texture balltexture;
sf::Clock ballclock;



TextInput Player1("", &arial, 16, 200, 50, 10, 70, sf::Color::White, sf::Color::Black);
TextInput Player2("", &arial, 16, 200, 50, 590, 70, sf::Color::White, sf::Color::Black);

bool games = false;
int ballSpeed = 2;
int platformSpeed = 2;
int touches = 0;
bool winer;


enum Mode {
	singlePlayer,
	multiplayer
};


Mode mode = Mode::multiplayer;

