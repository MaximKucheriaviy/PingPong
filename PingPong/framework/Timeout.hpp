#ifndef TIMEOUT_HPP
#define TIMEOUT_HPP

class Timeout {
public:
	Timeout(void(*callback)(), int delay) {
		this->callback = callback;
		this->delay = delay;
	}
	void run() {
		if (ran) {
			return;
		}
		if (clock.getElapsedTime().asMilliseconds() < delay) {
			return;
		}
		(*callback)();
		ran = true;
	}
	bool isRan() {
		return ran;
	}
protected:
	sf::Clock clock;
	int delay;
	void(*callback)();
	bool ran = false;
};

#endif // !TIMEOUT_HPP
