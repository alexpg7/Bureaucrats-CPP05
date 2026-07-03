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

	AForm *request2 = intern.makeForm("Random name", "Target");
	delete request;
	delete request2;
	return 0;
}
