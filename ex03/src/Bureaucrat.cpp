#include "Bureaucrat.hpp"
#include <sstream>
#include <string>

#define ERRMSG "possible grade is between 1 to 150\n"
#define EXEC " executed "

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

std::runtime_error	Bureaucrat::GradeTooHighException(int grade) const
{
	std::stringstream ss;

	ss << grade;
	std::string gradeStr = ss.str();
	return std::runtime_error("grade " +  gradeStr + " is too high!\n" + ERRMSG);
}

std::runtime_error	Bureaucrat::GradeTooLowException(int grade) const
{
	std::stringstream ss;

	ss << grade;
	std::string gradeStr = ss.str();
	return std::runtime_error("grade " +  gradeStr + " is too low!\n" + ERRMSG);
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

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn’t sign " << form.getName()
			<< " because " << this->_name << " doesn't meet the required grade.\n";
	}
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << EXEC << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
	return os;
}
