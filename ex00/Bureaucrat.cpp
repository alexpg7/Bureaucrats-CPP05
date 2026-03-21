#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur): _name(bur.getName()), _grade(bur.getGrade())
{
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, const unsigned int grade): _name(name), _grade(grade)
{
	if (_grade > 150)
		throw (GradeTooLowException());
	else if (_grade < 1)
		throw (GradeTooHighException());

	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bur)
{
	if (this != &bur)
		_grade = bur._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return (os);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
	{
		throw (GradeTooHighException());
		return ;
	}
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
	{
		throw (GradeTooLowException());
		return ;
	}
	this->_grade++;
}

const std::string	Bureaucrat::getName() const
{
	return this->_name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low. Grade must be between 1 and 150.");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high. Grade must be between 1 and 150.");
}
