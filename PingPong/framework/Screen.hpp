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
		active = true;
	}
	void disable() {
		active = false;
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
protected:
	vector<Box*> objects;
	vector<Process*> proceses;
	sf::RenderWindow* window = NULL;
	bool active = false;
};


#endif // !SCREEN_HPP
