#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	ft_presidential()
{
	std::cout << "\n################# PRESIDENTIAL ##################\n" << std::endl;
	PresidentialPardonForm	form1 = PresidentialPardonForm("Guilty");
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
	for (int i = 0; i < 125; i++)
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
	std::cout << "\nIncrement grade and execute it some times:" << std::endl;
	for (int i = 0; i < 20; i++)
		bur2.incrementGrade();
	bur2.executeForm(form1);
}

void	ft_robotomy()
{
	std::cout << "\n################### ROBOTOMY ####################\n" << std::endl;
	RobotomyRequestForm	form1 = RobotomyRequestForm("alpascua");
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
	for (int i = 0; i < 80; i++)
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
	std::cout << "\nIncrement grade and execute it some times:" << std::endl;
	for (int i = 0; i < 30; i++)
		bur2.incrementGrade();
	for (int i = 0; i < 10; i++)
		bur2.executeForm(form1);
}

void	ft_shrubbery()
{
	std::cout << "\n################### SHRUBBERY ###################\n" << std::endl;
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
	std::cout << "\nIncrement grade and execute it:" << std::endl;
	for (int i = 0; i < 8; i++)
		bur2.incrementGrade();
	bur2.executeForm(form1);
	std::cout << "\nShow what's inside the *_shrubbery file:" << std::endl;
	system("cat *_shrubbery");
}

int	main(void)
{
	ft_shrubbery();
	ft_robotomy();
	ft_presidential();
}
