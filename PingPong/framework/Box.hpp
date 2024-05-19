#ifndef BOX_HPP
#define BOX_HPP

class Box {
public:
	Box(int width, int height, int x, int y, sf::Color color = sf::Color::White) {
		shape = sf::RectangleShape(sf::Vector2f(width, height));
		shape.setPosition(x, y);
		shape.setFillColor(color);
	}
	virtual void display() {
		if (window == NULL || !enabled) {
			return;
		}
		window->draw(shape);
		process();
	}

	virtual void process() {

	}

	void setPosition(float x, float y) {
		shape.setPosition(x, y);
	}

	void setWindow(sf::RenderWindow* window) {
		if (this->window != NULL) {
			return;
		}
		this->window = window;
	}
	virtual void eventListener(sf::Event* event) {

	}

	sf::FloatRect getBounds() {
		return shape.getGlobalBounds();
	}

	void setTexture(sf::Texture* texture) {
		shape.setTexture(texture);
	}
	void setTextureRect(int x, int y, int x1, int y1) {
		shape.setTextureRect(sf::IntRect(x, y, x1 - x, y1 - y));
	}
	void enable() {
		enabled = true;
	}
	void disable() {
		enabled = false;
	}
protected:
	sf::RectangleShape shape;
	sf::RenderWindow* window = NULL;
	bool enabled = true;
};


#endif 
