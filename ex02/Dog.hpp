#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* brain;
	public:
		Dog(void);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog(void);

		void makeSound(void) const;
		bool setIdea(int index, const std::string& idea);
		bool getIdea(int index, std::string& out) const;
};

#endif
