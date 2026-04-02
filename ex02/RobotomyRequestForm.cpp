#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request", 72, 45), _target("DefaultPlace")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm (const std::string target)
	: AForm("Robotomy Request", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy), _target(copy._target)
{
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
		return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (this->isSigned() != 1)
		throw (AForm::FormNotSignedException());

	if (executor.getGrade() > this->getExecutionGrade())
		throw (AForm::GradeTooLowException());

	if (rand() % 2 == 1)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}

