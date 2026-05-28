#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

static void	printSection(const std::string& title) {
	std::cout << std::endl;
	std::cout << "=== " << title << " ===" << std::endl;
}

static void	destroyAnimals(Animal** animals, int count) {
	for (int i = 0; i < count; ++i) {
		delete animals[i];
		animals[i] = 0;
	}
}

static void	printIdea(const std::string& label, bool success, const std::string& idea) {
	std::cout << label << ": ";
	if (success)
		std::cout << idea;
	else
		std::cout << "[invalid index]";
	std::cout << std::endl;
}

int	main(void) {
	const int	animalCount = 4;
	Animal*		animals[animalCount] = {0};
	std::string	idea;

	printSection("Animal Array");
	try {
		for (int i = 0; i < animalCount / 2; ++i)
			animals[i] = new Dog();
		for (int i = animalCount / 2; i < animalCount; ++i)
			animals[i] = new Cat();
	} catch (...) {
		destroyAnimals(animals, animalCount);
		std::cerr << "Failed to create animal array" << std::endl;
		return (1);
	}
	for (int i = 0; i < animalCount; ++i) {
		std::cout << animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}

	printSection("Delete Animals");
	destroyAnimals(animals, animalCount);

	printSection("Dog Copy Constructor");
	Dog originalDog;
	originalDog.setIdea(0, "bone");
	Dog copiedDog(originalDog);
	originalDog.setIdea(0, "new bone");
	printIdea("originalDog idea[0]", originalDog.getIdea(0, idea), idea);
	printIdea("copiedDog idea[0]", copiedDog.getIdea(0, idea), idea);

	printSection("Cat Assignment");
	try{
		Cat originalCat;
		Cat assignedCat;
		originalCat.setIdea(1, "sun");
		assignedCat = originalCat;
		originalCat.setIdea(1, "moon");
		printIdea("originalCat idea[1]", originalCat.getIdea(1, idea), idea);
		printIdea("assignedCat idea[1]", assignedCat.getIdea(1, idea), idea);
	} catch (...) {
		std::cout << "Failed during Cat assignment test" << std::endl;
		return(1);
	}
	return (0);
}
