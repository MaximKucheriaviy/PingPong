#ifndef TEXT_INPUT_HPP	
#define TEXT_INPUT_HPP	
class TextInput :public TextBox {
public:
	TextInput(string text, sf::Font* font, int textSize, int width, int height, int x, int y, sf::Color color = sf::Color::White, sf::Color textColor = sf::Color::White) : TextBox(text, font, textSize, width, height, x, y, color, textColor) {
		shape.setOutlineColor(sf::Color::Red);
		this->line = text;
	}
	void eventListener(sf::Event* event) {
		if (event->type == sf::Event::MouseButtonReleased) {
			mouseListener(event);
		}
		if (event->type == sf::Event::KeyPressed && active) {
			keyEventListener(event);
		}
	}
	void process() {
		if (active) {
			shape.setOutlineThickness(3);
		}
		else {
			shape.setOutlineThickness(0);
		}
	}
	string getLine() {
		return line;
	}
protected:
	void mouseListener(sf::Event* event) {
		if (!shape.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y)) {
			active = false;
			return;
		}
		active = true;
	}
	void keyEventListener(sf::Event* event) {
		char symbol = 0;
		bool update = false;
		if (event->key.code < 26) {
			update = true;
			if (event->key.shift) {
				symbol = event->key.code + 'A';
			}
			else {
				symbol = event->key.code + 97;
			}
		}
		else if (event->key.code == sf::Keyboard::Space) {
			update = true;
			symbol = ' ';
		}
		else if (event->key.code == sf::Keyboard::BackSpace) {
			if (line.size() == 0) {
				return;
			}
			line.resize(line.size() - 1);
			text.setString(line);
			return;
		}

		if (update) {
			if (text.getGlobalBounds().width + text.getCharacterSize() > shape.getGlobalBounds().width) {
				return;
			}
			if (symbol != 0) {
				line.push_back(symbol);
			}
			text.setString(line);
		}
	}
	bool active = false;
	string line = "";
};


#endif 
