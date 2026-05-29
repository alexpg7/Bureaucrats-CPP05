#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

typedef AForm* (*FormCreator)(const std::string&);

static AForm* createPardon(const std::string& target) {
	return new PresidentialPardonForm(target);
}

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makeForm(std::string name, std::string target)
{
	int i = 0;
	PresidentialPardonForm	pardon;
	ShrubberyCreationForm	shrubbey;
	RobotomyRequestForm		robotomy;

	std::string	_names[] = {
		pardon.getName(),
		shrubbey.getName(),
		robotomy.getName()
	};

	FormCreator creators[] = {
		createPardon,
		createShrubbery,
		createRobotomy
	};

	while (i < 3)
	{
		if (name == _names[i])
		{
			AForm*	ret = creators[i](target);
			std::cout << "Intern creates " << name << std::endl;
			return ret;
		}
		i++;
	}
	std::cerr << "Form \"" << name << "\" does not exist" << std::endl;
	return nullptr;
}
