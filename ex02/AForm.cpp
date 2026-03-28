#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm()
{
	return ;
}
AForm::AForm(const AForm &form): _issigned(form.isSigned()), _signgrade(form.getSignGrade()), _execgrade(form.getExecutionGrade())
{
	return ;
}
AForm::AForm(const std::string name, const unsigned int signgrade, const unsigned int execgrade):
_name(name), _signgrade(signgrade), _execgrade(signgrade)
{
	if (_signgrade > 150 || _execgrade > 150)
		throw (GradeTooLowException());
	else if (_signgrade < 1 || _execgrade < 1)
		throw (GradeTooHighException());

	return ;
}
AForm::~AForm()
{
	return ;
}

AForm&	AForm::operator=(const AForm& form)
{
	if (this != &form)
		_issigned = form.isSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName() << ", form:" << std::endl;
	os << "Sign grade " << form.getSignGrade() << std::endl;
	os << "Execution grade " << form.getExecutionGrade() << std::endl;
	return (os);
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::isSigned() const
{
	return (this->_issigned);
}

const unsigned int	AForm::getSignGrade() const
{
	return (this->_signgrade);
}

const unsigned int	AForm::getExecutionGrade() const
{
	return (this->_execgrade);
}

void	AForm::beSigned(const Bureaucrat& bur)
{
	if (this->_signgrade >= bur.getGrade())
		this->_issigned = true;
	else
		throw (GradeTooLowException());
	return ;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low. Grade must be between 1 and 150.");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high. Grade must be between 1 and 150.");
}