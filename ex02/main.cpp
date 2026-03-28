#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	AForm	form1 = AForm("norminette", 1, 1);
	AForm	form2 = AForm("TIG", 150, 150);
	Bureaucrat	bur2 = Bureaucrat("Bimba", 150);

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\nTry to assign a wrong grade:" << std::endl;
	try
	{
		AForm	form3 = AForm("My exercise", 165, 165);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\nTry to sign wrongly:" << std::endl;
	bur2.signForm(form1);

	std::cout << "\nSign correctly:" << std::endl;
	bur2.signForm(form2);
}
