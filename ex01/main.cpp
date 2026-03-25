#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form	form1 = Form("norminette", 1, 1);
	Form	form2 = Form("TIG", 150, 150);
	Bureaucrat	bur2 = Bureaucrat("Bimba", 150);

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	std::cout << "\nTry to assign a wrong grade:" << std::endl;
	try
	{
		Form	form3 = Form("My exercise", 165, 165);
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
