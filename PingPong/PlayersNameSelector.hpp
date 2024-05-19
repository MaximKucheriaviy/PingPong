#include <iostream>

TextInput Player1("", &arial, 16, 200, 50, 10, 70, sf::Color::White, sf::Color::Black);
TextBox pl1("Player 1 name", &arial, 20, 200, 50, 10, 10, sf::Color::Red, sf::Color::Black);
TextInput Player2("", &arial, 16, 200, 50, 590, 70, sf::Color::White, sf::Color::Black);
TextBox pl2("Player 2 name", &arial, 20, 200, 50, 590, 10, sf::Color::Red, sf::Color::Black);
Button per("Submit", &arial, 20, 100, 50, 350, 10, sf::Color::Green, sf::Color::Black);

void callback() {
	cout << Player1.getLine() << endl <<  Player2.getLine() << endl;
	//return Player1.getLine(), Player2.getLine();

}
void playersNameSelector() {
	nameSelector.addObject(&Player1);
	nameSelector.addObject(&pl1);
	nameSelector.addObject(&Player2);
	nameSelector.addObject(&pl2);
	nameSelector.addObject(&per);
	per.setCallback(&callback);

	app.addScreen(&nameSelector);
	app.run();
}
