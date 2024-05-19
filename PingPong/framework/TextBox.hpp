#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

class TextBox : public Box {
public:
	TextBox(string text, sf::Font* font, int textSize, int width, int height, int x, int y, sf::Color color = sf::Color::White, sf::Color textColor = sf::Color::White) : Box(width, height, x, y, color) {
		this->text.setFont(*font);
		this->text.setString(text);
		this->text.setCharacterSize(textSize);
		this->text.setFillColor(textColor);
	}
	enum TextAlign {
		left,
		center,
		right,
	};
	void display() {
		if (window == NULL || !enabled) {
			return;
		}
		aligntText();
		window->draw(shape);
		window->draw(text);
		process();
	}
	void setAlign(TextAlign align) {
		this->align = align;
	}
	void setText(string text) {
		this->text.setString(text);
	}
protected:
	sf::Text text;
	TextAlign align = center;
	void aligntText() {
		sf::FloatRect shapeRect = shape.getGlobalBounds();
		sf::FloatRect textRect = text.getGlobalBounds();
		float yOffset = (shapeRect.height - text.getCharacterSize()) / 2;
		float xOffset;
		if (align == left) {
			xOffset = 10;
		}
		else if (align == center) {
			xOffset = (shapeRect.width - textRect.width) / 2;
		}
		else {
			xOffset = (shapeRect.width - textRect.width) - 20;
		}
		text.setPosition(shapeRect.left + xOffset, shapeRect.top + yOffset);
	}
};

#endif // !TEXTBOX_HPP
