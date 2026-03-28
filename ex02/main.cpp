#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	ShrubberyCreationForm	form1 = ShrubberyCreationForm("Campus42");
	Bureaucrat	bur2 = Bureaucrat("Bimba", 150);

	std::cout << form1 << std::endl;

	std::cout << "\nTry to sign form wrongly:" << std::endl;
	try
	{
		bur2.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nIncrement grade and sign it:" << std::endl;
	for (int i = 0; i < 5; i++)
		bur2.incrementGrade();
	bur2.signForm(form1);
	std::cout << "\nTry to execute form wrongly:" << std::endl;
	try
	{
		bur2.executeForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nIncrement grade and sign it:" << std::endl;
	for (int i = 0; i < 8; i++)
		bur2.incrementGrade();
	bur2.executeForm(form1);
}
