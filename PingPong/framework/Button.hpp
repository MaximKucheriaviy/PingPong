#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button : public TextBox {
public:
	Button(string text, sf::Font* font, int textSize, int width, int height, int x, int y, sf::Color color = sf::Color::White, sf::Color textColor = sf::Color::White) : TextBox(text, font, textSize, width, height, x, y, color, textColor) {
		
	}
	void eventListener(sf::Event* event) {
		if (!enabled) {
			return;
		}
		if (event->type != sf::Event::MouseButtonReleased) {
			return;
		}
		if (!shape.getGlobalBounds().contains(event->mouseButton.x, event->mouseButton.y)) {
			return;
		}
		if (callback == NULL) {
			return;
		}
		(*callback)();
	}
	void setCallback(void (*callback)()) {
		this->callback = callback;
	}
protected:
	void (*callback)() = NULL;
};

#endif // !BUTTON_HPP
