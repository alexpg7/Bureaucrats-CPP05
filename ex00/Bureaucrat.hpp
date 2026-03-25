#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class	Bureaucrat
{
	private:
		const std::string	_name = "Unnamed Bureaucrat";
		unsigned int		_grade = 150;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &bur);
		Bureaucrat(const std::string name, const unsigned int grade);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& bur);
		const std::string	getName() const;
		unsigned int	getGrade() const;
		void	incrementGrade();
		void	decrementGrade();

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bur);

#endif
