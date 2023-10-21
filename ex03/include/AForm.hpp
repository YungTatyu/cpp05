#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const int	_gradeToSign;
	const int	_gradeToExec;
	bool	_isSigned;
	bool	_isGradeTooHigh(const int& grade) const;
	bool	_isGradeTooLow(const int& grade) const;
	std::runtime_error	GradeTooHighException(int grade, std::string errMsg) const;
	std::runtime_error	GradeTooLowException(int grade, std::string errMsg) const;
	AForm();
public:
	AForm(const std::string& name, const int& gradeToSign, const int& gradeToExec);
	AForm(const AForm& other);
	AForm&	operator=(const AForm& other);
	virtual ~AForm();
	const std::string	getName() const;
	const int&	getGradeToSign() const;
	const int&	getGradeToExec() const;
	const bool&	getIsSigned() const;
	void	beSigned(const Bureaucrat& b);
	virtual void	execute(Bureaucrat const& executor) const = 0;
	const static int	highestGrade = 1;
	const static int	lowestGrade = 150;
};

std::ostream&	operator<<(std::ostream& os, const AForm &obj);

#endif