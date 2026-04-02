#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon", 25, 5), _target("DefaultPlace")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm (const std::string target)
	: AForm("Presidential Pardon", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
	: AForm(copy), _target(copy._target)
{
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
		return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (this->isSigned() != 1)
		throw (AForm::FormNotSignedException());

	if (executor.getGrade() > this->getExecutionGrade())
		throw (AForm::GradeTooLowException());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

