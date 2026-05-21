#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal("Cat"), brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
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

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound(void) const {
	std::cout << "Cat: * meow meow *" << std::endl;
}

bool Cat::setIdea(int index, const std::string& idea){
	return (brain->setIdea(index, idea));
}

bool Cat::getIdea(int index, std::string& out) const {
	return (brain->getIdea(index, out));
}
