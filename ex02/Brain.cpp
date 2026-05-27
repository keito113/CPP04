#include "Brain.hpp"
#include <iostream>

Brain::Brain(void){
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other){
	std::cout << "Brain copy constructor called" << std::endl;
  	for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other){
		for (int i = 0; i < 100; ++i)
        	this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void){
	std::cout << "Brain destructor called" << std::endl;
}

bool Brain::setIdea(int index, const std::string& idea){
	if (index < 0 || index >= 100)
		return (false);
	this->ideas[index] = idea;
	return (true);
}

bool Brain::getIdea(int index, std::string& out) const {
	if (index < 0 || index >= 100)
		return (false);
	out = ideas[index];
	return (true);
}
