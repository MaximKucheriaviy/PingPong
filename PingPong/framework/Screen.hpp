#ifndef SCREEN_HPP
#define SCREEN_HPP
class Screen {
public:
	void addObject(Box* object) {
		objects.push_back(object);
		if (this->window == NULL) {
			return;
		}
		object->setWindow(window);
	}
	void display() {
		if (window == NULL) {
			return;
		}
		if (!active) {
			for (int i = 0; i < proceses.size(); i++) {
				proceses[i]->reset();
			}
			return;
		}
		for (int i = 0; i < proceses.size(); i++) {
			proceses[i]->run();
		}
		for (int i = 0; i < timeouts.size(); i++) {
			timeouts[i].run();
		}
		for (int i = 0; i < timeouts.size(); i++) {
			if (timeouts[i].isRan()) {
				timeouts.erase(timeouts.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < objects.size(); i++) {
			objects[i]->display();
		}
	}
	void setWindow(sf::RenderWindow* window) {
		if (this->window != NULL) {
			return;
		}
		this->window = window;
		for (int i = 0; i < objects.size(); i++) {
			objects[i]->setWindow(window);
		}
	}
	void enable() {
		for (int i = 0; i < objects.size(); i++) {
			objects[i]->resetClocks();
		}
		active = true;
	}
	void disable() {
		active = false;
	}
	void setTimout(Timeout t) {
		timeouts.push_back(t);
	}
	void eventListener(sf::Event* event) {
		if (!active) {
			return;
		}
		for (int i = 0; i < objects.size(); i++) {
			objects[i]->eventListener(event);
		}
	}
	bool isActive() {
		return active;
	}
	void setProcess(Process* process) {
		proceses.push_back(process);
	}

	vector<Box*> getObjects() {
		return objects;
	}
	void deleteObjects() {
		objects.clear();
	}
protected:
	vector<Box*> objects;
	vector<Process*> proceses;
	vector<Timeout> timeouts;
	sf::RenderWindow* window = NULL;
	bool active = false;
};


#endif // !SCREEN_HPP
