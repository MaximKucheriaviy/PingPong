#ifndef MOVABLE_BOX
#define MOVABLE_BOX

class MovableBox : public Box {
public:
	MovableBox(int width, int height, int x, int y, sf::Color color = sf::Color::White) : Box(width, height, x, y ,color) {
		
	}
	void move(float x, float y) {
		if (moveClock.getElapsedTime().asMilliseconds() < 7) {
			return;
		}
		shape.move(x * moveClock.getElapsedTime().asMilliseconds() / 7, y * moveClock.getElapsedTime().asMilliseconds() / 7);
		moveClock.restart();
	}
protected:
	sf::Clock moveClock;
};


#endif // !MOVABLE_BOX
