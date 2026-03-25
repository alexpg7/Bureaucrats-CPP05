#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	bur1 = Bureaucrat("Okto", 1);
	Bureaucrat	bur2 = Bureaucrat("Bimba", 150);

	std::cout << bur1 << std::endl;
	std::cout << bur2 << std::endl;

	std::cout << "\nTry to assign a wrong grade:" << std::endl;
	try
	{
		Bureaucrat	bur3 = Bureaucrat("alpascua", 165);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTry to higher a grade:" << std::endl;
	try
	{
		bur1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
