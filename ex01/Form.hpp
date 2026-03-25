#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name = "Unnamed Form";
		bool				_issigned = false;
		const unsigned int	_signgrade = 150;
		const unsigned int	_execgrade = 150;
	public:
		Form();
		Form(const Form &bur);
		Form(const std::string name, const unsigned int signgrade, const unsigned int execgrade);
		~Form();
		Form& operator=(const Form& form);
		const std::string	getName() const;
		bool				isSigned() const;
		const unsigned int	getSignGrade() const;
		const unsigned int	getExecutionGrade() const;
		void				beSigned(const Bureaucrat& bur);

	class GradeTooHighException : public std::exception
	{
		public:
			const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif