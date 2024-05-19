#ifndef EVENTLISTENER_HPP
#define EVENTLISTENER_HPP
class EventListener : public Box {
public:
	EventListener(void (*callback)(sf::Event*)) : Box(0, 0, 0, 0, sf::Color::Transparent) {
		this->callback = callback;
	}
	virtual void eventListener(sf::Event* event) {
		(*callback)(event);
	}
protected:
	void (*callback)(sf::Event*);
};
#endif // !EVENTLISTENER_HPP
