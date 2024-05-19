#ifndef PROCESS_HPP
#define PROCESS_HPP

class Process {
public:
	Process(int delayTimer, void (*callback)())
	{
		this->delayTimer = delayTimer;
		this->callback = callback;
	}

	void reset() {
		clock.restart();
	}
	void run() {
		if (clock.getElapsedTime().asMilliseconds() < delayTimer) {
			return;
		}
		clock.restart();
		(*callback)();
	}
protected:
	void (*callback)();
	sf::Clock clock;
	int delayTimer = 0;
};


#endif // !PROCESS_HPP
