#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int	_grade;
	Bureaucrat();
	std::runtime_error	GradeTooHighException(int grade) const;
	std::runtime_error	GradeTooLowException(int grade) const;
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
	void	signForm(AForm& form);
	void	executeForm(AForm const& form);
	const static int	highestGrade = 1;
	const static int	lowestGrade = 150;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &obj);

#endif