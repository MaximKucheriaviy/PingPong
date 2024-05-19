#ifndef APLICATION_HPP
#define APLICATION_HPP

class Application {
public:
	static string intToString(int number) {
		bool minus = number < 0;
		if (number == 0) {
			return "0";
		}
		if (minus) {
			number *= -1;
		}
		string line;
		while (number != 0) {
			int n = number % 10;
			number -= n;
			number /= 10;
			line.insert(0, 1, n + '0');
		}
		if (minus) {
			line.insert(0, 1, '-');
		}
		return line;
	}
	Application(sf::VideoMode vm = sf::VideoMode(800, 600), string name = "") {
		window = new sf::RenderWindow(vm, name);
	}
	void addScreen(Screen* screen) {
		screens.push_back(screen);
		screen->setWindow(window);
	}
	void disableAllScreens() {
		for (int i = 0; i < screens.size(); i++) {
			screens[i]->disable();
		}
	}
	void run() {
		while (window->isOpen())
		{
			sf::Event event;
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window->close();
				}
				for (int i = 0; i < screens.size(); i++) {
					if (screens[i]->isActive()) {
						screens[i]->eventListener(&event);
						break;
					}
				}
			}
			window->clear();
			for (int i = 0; i < screens.size(); i++) {
				screens[i]->display();
			}
			window->display();
		}
	}
	sf::RenderWindow* getWindow() {
		return window;
	}
protected:
	vector<Screen*> screens;
	sf::RenderWindow* window;
};

#endif // !APLICATION_HPP
