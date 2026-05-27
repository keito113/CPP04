#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
	protected:
		std::string type;
		Animal(void);
		Animal(const std::string& initialType);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);

	public:
		virtual ~Animal(void);

		const std::string& getType(void) const;
		virtual void makeSound(void) const = 0;
};

#endif
