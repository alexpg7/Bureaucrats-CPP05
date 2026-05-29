#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	intern;

	AForm *request = intern.makeForm("Robotomy Request", "Target");
	Bureaucrat	bur("okto", 1);
	bur.signForm(*request);

	intern.makeForm("Random name", "Target");
}
