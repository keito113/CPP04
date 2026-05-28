#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal {
	protected:
		std::string type;
		WrongAnimal(const std::string& initialType);

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal(void);

		const std::string& getType(void) const;
		void makeSound(void) const;
};

#endif
