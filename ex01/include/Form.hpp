#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int	_gradeToSign;
	const int	_gradeToExec;
	bool	_isSigned;
	std::runtime_error	GradeTooHighException(int grade);
	std::runtime_error	GradeTooLowException(int grade);
	Form();
public:
	Form(const std::string& name, const int& gradeToSign, const int& gradeToExec);
	Form(const Form& other);
	Form&	operator=(const Form& other);
	~Form();
	const int	getName() const;
	const int	getGradeToSign() const;
	const int	getGradeToExec() const;
	const int	getIsSigned() const;
	void	beSigned(const Bureaucrat& b);
	const static int	highestGrade = 1;
	const static int	lowestGrade = 150;
};

std::ostream&	operator<<(std::ostream& os, const Form &obj);

#endif