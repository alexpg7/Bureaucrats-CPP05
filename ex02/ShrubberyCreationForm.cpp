#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), _target("DefaultPlace")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm (const std::string target)
	: AForm("Shrubbery Creation", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	: AForm(copy ), _target(copy._target)
{
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
		return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (this->isSigned() != 1)
		throw ( AForm::FormNotSignedException() );

	if (executor.getGrade() > this->getExecutionGrade())
		throw ( AForm::GradeTooLowException() );

	std::string fileName = _target + "_shrubbery";
	std::ofstream file(fileName);
	//print here the trees
	file << "tree" << std::endl;
}

