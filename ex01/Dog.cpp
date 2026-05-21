#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) : Animal("Dog"), brain(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if(this == &other)
		return(*this);
	Brain* newBrain = new Brain(*other.brain);
	try {
		Animal::operator=(other);
	} catch (...) {
		delete newBrain;
		throw;
	}
	delete brain;
	brain = newBrain;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound(void) const {
	std::cout << "Dog: * woof woof *" << std::endl;
}

bool Dog::setIdea(int index, const std::string& idea){
	return (brain->setIdea(index, idea));
}

bool Dog::getIdea(int index, std::string& out) const {
	return (brain->getIdea(index, out));
}
