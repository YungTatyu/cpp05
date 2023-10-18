#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int	_grade;
	Bureaucrat();
	std::runtime_error	GradeTooHighException(int grade);
	std::runtime_error	GradeTooLowException(int grade);
	bool	_isGradeTooHigh() const;
	bool	_isGradeTooLow() const;
public:
	Bureaucrat(const std::string name, const int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat &obj);
	const std::string&	getName() const;
	const int&	getGrade() const;
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(const Form& form);
	const static int	highestGrade = 1;
	const static int	lowestGrade = 150;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &obj);

#endif