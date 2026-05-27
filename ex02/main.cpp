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

static void	destroyAnimals(Animal** animals, int count) {
	for (int i = 0; i < count; ++i) {
		delete animals[i];
		animals[i] = 0;
	}
}

static void	printIdeaResult(const std::string& label, bool success, const std::string& idea) {
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

	//Animal directAnimal;
	//Animal* directPointer = new Animal();

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
	printIdeaResult("originalDog idea[0]", originalDog.getIdea(0, idea), idea);
	printIdeaResult("copiedDog idea[0]", copiedDog.getIdea(0, idea), idea);

	printSection("Cat Assignment");
	Cat originalCat;
	Cat assignedCat;
	originalCat.setIdea(1, "sun");
	assignedCat = originalCat;
	originalCat.setIdea(1, "moon");
	printIdeaResult("originalCat idea[1]", originalCat.getIdea(1, idea), idea);
	printIdeaResult("assignedCat idea[1]", assignedCat.getIdea(1, idea), idea);

	printSection("Self Assignment");
	Cat& sameCat = assignedCat;
	Dog& sameDog = copiedDog;
	assignedCat = sameCat;
	copiedDog = sameDog;
	printIdeaResult("assignedCat idea[1]", assignedCat.getIdea(1, idea), idea);
	printIdeaResult("copiedDog idea[0]", copiedDog.getIdea(0, idea), idea);

	printSection("Bounds Check");
	printIdeaResult("dog idea[-1]", originalDog.getIdea(-1, idea), idea);
	printIdeaResult("dog idea[100]", originalDog.getIdea(100, idea), idea);
	std::cout << "set idea[-1]: " << (originalDog.setIdea(-1, "bad") ? "ok" : "rejected") << std::endl;
	std::cout << "set idea[100]: " << (originalDog.setIdea(100, "bad") ? "ok" : "rejected") << std::endl;

	printSection("Wrong Animal");
	WrongCat			wrongCat;
	const WrongAnimal&	wrongRef = wrongCat;
	const WrongAnimal*	wrongPtr = &wrongCat;

	wrongCat.makeSound();
	wrongRef.makeSound();
	wrongPtr->makeSound();

	return (0);
}
