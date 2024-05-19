#ifndef PHYS_BODY_HPP
#define PHYS_BODY_HPP
class PhysicalBody : public MovableBox {
public:
	PhysicalBody(int width, int height, int x, int y, sf::Color color = sf::Color::White) : MovableBox(width, height, x, y, color) {

	}
	virtual void process() {
		move(xSpeed, ySpeed);
		if (collideBorder) {
			borderCollaider();
		}
		gravityProcess();
	}
	void setXSpeed(float xSpeed) {
		this->xSpeed = xSpeed;
	}
	void setYSpeed(float ySpeed) {
		this->ySpeed = ySpeed;
	}
	void borderCollaider() {
		if (shape.getPosition().x < 0) {
			shape.setPosition(0, shape.getPosition().y);
			xSpeed *= -1;
		}
		if (shape.getPosition().x + shape.getSize().x > window->getSize().x) {
			shape.setPosition(window->getSize().x - shape.getSize().x, shape.getPosition().y);
			xSpeed *= -1;
		}

		if (shape.getPosition().y < 0) {
			shape.setPosition(shape.getPosition().x, 0);
			ySpeed *= -1;
		}
		if (shape.getPosition().y + shape.getSize().y > window->getSize().y) {
			shape.setPosition(shape.getPosition().x, window->getSize().y - shape.getSize().y);
			ySpeed *= -1;
			canJump = true;
		}

	}
	void setColideBorder(bool value) {
		this->collideBorder = value;
	}
	void gravityProcess() {
		if (gravityTimer.getElapsedTime().asMilliseconds() < 10) {
			return;
		}
		gravityTimer.restart();
		ySpeed += gravity * 0.1;
		ySpeed *= airFiction;
		xSpeed *= airFiction;
	}
	void setGravity(float gravity) {
		this->gravity = gravity;
	}
	float getYSpeed() {
		return ySpeed;
	}
	float getXSpeed() {
		return xSpeed;
	}
	void setAirDencity(float ad) {
		this->airFiction = ad;
	}

	void collide(PhysicalBody* target) {
		if (!shape.getGlobalBounds().intersects(target->getBounds())) {
			return;
		}
		sf::Vector2f startPosition = shape.getPosition();
		int up = 0;
		int dowm = 0;
		int left = 0;
		int right = 0;

		

		float step = 0.1;
		while (shape.getGlobalBounds().intersects(target->getBounds())) {
			shape.move(0, step * -1);
			up++;
		}
		sf::Vector2f tartgetPosition = shape.getPosition();
		int colisionType = 0;
		shape.setPosition(startPosition);
		while (shape.getGlobalBounds().intersects(target->getBounds())) {
			shape.move(0, step);
			dowm++;
		}
		if (dowm < up) {
			tartgetPosition = shape.getPosition();
			colisionType = 1;
		}

		shape.setPosition(startPosition);
		while (shape.getGlobalBounds().intersects(target->getBounds())) {
			shape.move(step, 0);
			right++;
		}
		if (right < up && right < dowm) {
			colisionType = 2;
			tartgetPosition = shape.getPosition();
		}


		shape.setPosition(startPosition);
		while (shape.getGlobalBounds().intersects(target->getBounds())) {
			shape.move(step * -1, 0);
			left++;
		}
		if (left < up && left < dowm && left < right) {
			tartgetPosition = shape.getPosition();
			colisionType = 3;
		}

		shape.setPosition(tartgetPosition);

		if ( colisionType == 0) {
			ySpeed *= -1;
			ySpeed *= target->density;
			canJump = true;
		}
		else if (colisionType == 1) {
			ySpeed *= -1;
		}
		if (colisionType == 2 || colisionType == 3) {
			xSpeed *= -1;
			xSpeed *= target->density;
		}
	}
	void jump(float jumpForce) {
		if (!canJump) {
			return;
		}
		ySpeed = jumpForce * -1;
		canJump = false;
	}
protected:
	sf::Clock gravityTimer;
	float xSpeed = 0;
	float ySpeed = 0;
	bool collideBorder = false;
	float gravity = 0;
	float airFiction = 1;
	float density = 0;
	bool canJump = false;
};



#endif // !PHYS_BODY_HPP
