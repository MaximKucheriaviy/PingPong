#include <iostream>


TextBox pl1("Player 1 name", &arial, 20, 200, 50, 10, 10, sf::Color::Red, sf::Color::Black);
TextBox pl2("Player 2 name", &arial, 20, 200, 50, 590, 10, sf::Color::Red, sf::Color::Black);
Button per("Submit", &arial, 20, 100, 50, 350, 10, sf::Color::Green, sf::Color::Black);

void callback() {
	if (mode != singlePlayer) {
		if (Player1.getLine() == "") {
			cout << "No name in Player 1" << endl;
		}
		else if(Player2.getLine() == "") {
			cout << "No name in Player 2" << endl;
		}
		else if (Player1.getLine() == "" and Player1.getLine() == "") {
			cout << "No name" << endl;
		}
		else {
			cout << Player1.getLine() << endl << Player2.getLine() << endl;
			Gamest();
		}
	}
	else {
		if (Player1.getLine() == "") {
			cout << "No name" << endl;
		}
		else {
			cout << Player1.getLine() << endl;
			Gamest();
		}
	}
	//return Player1.getLine(), Player2.getLine();

}

void initSelectScreen() {
	if (mode != singlePlayer) {
		nameSelector.addObject(&Player1);
		nameSelector.addObject(&pl1);
		nameSelector.addObject(&Player2);
		nameSelector.addObject(&pl2);
	}
	else {
		pl1.setPosition(300, 10);
		pl1.setText("Player name");
		Player1.setPosition(300, 80);
		per.setPosition(350, 150);
		nameSelector.addObject(&Player1);
		nameSelector.addObject(&pl1);
	}
	nameSelector.addObject(&per);
}
void playersNameSelector() {
	
	per.setCallback(&callback);
	app.addScreen(&nameSelector);

}
