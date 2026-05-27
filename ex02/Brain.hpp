#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain(void);

		bool setIdea(int index, const std::string& idea);
		bool getIdea(int index, std::string& out) const;
};

#endif
