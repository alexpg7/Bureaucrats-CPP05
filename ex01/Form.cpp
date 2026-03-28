#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form()
{
	return ;
}
Form::Form(const Form &form): _issigned(form.isSigned()), _signgrade(form.getSignGrade()), _execgrade(form.getExecutionGrade())
{
	return ;
}
Form::Form(const std::string name, const unsigned int signgrade, const unsigned int execgrade):
_name(name), _signgrade(signgrade), _execgrade(execgrade)
{
	if (_signgrade > 150 || _execgrade > 150)
		throw (GradeTooLowException());
	else if (_signgrade < 1 || _execgrade < 1)
		throw (GradeTooHighException());

	return ;
}
Form::~Form()
{
	return ;
}

Form&	Form::operator=(const Form& form)
{
	if (this != &form)
		_issigned = form.isSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", form:" << std::endl;
	os << "Sign grade " << form.getSignGrade() << std::endl;
	os << "Execution grade " << form.getExecutionGrade();
	return (os);
}

const std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::isSigned() const
{
	return (this->_issigned);
}

const unsigned int	Form::getSignGrade() const
{
	return (this->_signgrade);
}

const unsigned int	Form::getExecutionGrade() const
{
	return (this->_execgrade);
}

void	Form::beSigned(const Bureaucrat& bur)
{
	if (this->_signgrade >= bur.getGrade())
		this->_issigned = true;
	else
		throw (GradeTooLowException());
	return ;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low. Grade must be between 1 and 150.");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high. Grade must be between 1 and 150.");
}