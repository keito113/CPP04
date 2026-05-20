#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

static void	printSection(const std::string& title) {
	std::cout << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

int	main(void) {
	printSection("Direct Objects");
	Animal	meta;
	Dog		dog;
	Cat		cat;

	std::cout << meta.getType() << std::endl;
	std::cout << dog.getType() << std::endl;
	std::cout << cat.getType() << std::endl;
	meta.makeSound();
	dog.makeSound();
	cat.makeSound();

	printSection("Polymorphism With Pointers");
	const Animal* animalPtr = new Animal();
	const Animal* dogPtr = new Dog();
	const Animal* catPtr = new Cat();

	std::cout << animalPtr->getType() << std::endl;
	std::cout << dogPtr->getType() << std::endl;
	std::cout << catPtr->getType() << std::endl;
	animalPtr->makeSound();
	dogPtr->makeSound();
	catPtr->makeSound();

	delete animalPtr;
	delete dogPtr;
	delete catPtr;

	printSection("Polymorphism With References");
	const Animal& dogRef = dog;
	const Animal& catRef = cat;

	dogRef.makeSound();
	catRef.makeSound();

	printSection("Wrong Animal");
	WrongCat			wrongCat;
	const WrongAnimal&	wrongRef = wrongCat;
	const WrongAnimal*	wrongPtr = &wrongCat;

	wrongCat.makeSound();
	wrongRef.makeSound();
	wrongPtr->makeSound();

	printSection("Copy And Assignment");
	Dog	copyDog(dog);
	Cat	assignedCat;
	Cat&	sameCat = assignedCat;

	assignedCat = cat;
	assignedCat = sameCat;
	copyDog.makeSound();
	assignedCat.makeSound();
	std::cout << copyDog.getType() << std::endl;
	std::cout << assignedCat.getType() << std::endl;

	return (0);
}
