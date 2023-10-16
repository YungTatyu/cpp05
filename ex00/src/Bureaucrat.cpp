#include "Bureaucrat.hpp"
#include <sstream>
#include <string>

#define ERR_MSG "possible grade is between 1 to 150\n"

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
	if (grade < highestGrade)
		throw GradeTooHighException(grade);
	else if (grade > lowestGrade)
		throw GradeTooLowException(grade);
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	this->operator=(obj);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
	{
		this->_grade = obj._grade;
	}
	return *this;
}

std::runtime_error	Bureaucrat::GradeTooHighException(int grade)
{
	std::stringstream ss;

	ss << grade;
	std::string gradeStr = ss.str();
	return std::runtime_error("grade " +  gradeStr + " is too high!\n" + ERR_MSG);
}

std::runtime_error	Bureaucrat::GradeTooLowException(int grade)
{
	std::stringstream ss;

	ss << grade;
	std::string gradeStr = ss.str();
	return std::runtime_error("grade " +  gradeStr + " is too low!\n" + ERR_MSG);
}

bool	Bureaucrat::_isGradeTooHigh() const
{
	return _grade <= highestGrade;
}

bool	Bureaucrat::_isGradeTooLow() const
{
	return _grade >= lowestGrade;
}

void	Bureaucrat::incrementGrade()
{
	if (_isGradeTooHigh())
	{
		throw GradeTooHighException(_grade - 1);
		return;
	}
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_isGradeTooLow())
	{
		throw GradeTooLowException(_grade + 1);
		return;
	}
	_grade++;
}

const std::string&	Bureaucrat::getName() const
{
	return this->_name;
}

const int&	Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
	return os;
}
