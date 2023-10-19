#include <sstream>
#include <string>
#include "AForm.hpp"

#define ERRMSG "possible grade is between 1 to 150\n"

AForm::AForm(const std::string& name, const int& gradeToSign, const int& gradeToExec)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false)
{
	bool	isGradeToSignOof = _isGradeTooHigh(gradeToSign); // gradeToSignが範囲外を格納
	bool	isGradeToExecOof = _isGradeTooHigh(gradeToExec); // gradeToExecが範囲外を格納

	if (isGradeToSignOof || isGradeToExecOof)
	{
		int	gradeToThrow = isGradeToSignOof ? gradeToSign : gradeToExec;
		throw GradeTooHighException(gradeToThrow, ERRMSG);
	}

	isGradeToSignOof = _isGradeTooLow(gradeToSign);
	isGradeToExecOof = _isGradeTooLow(gradeToExec);
	if (isGradeToSignOof || isGradeToExecOof)
	{
		int	gradeToThrow = isGradeToSignOof ? gradeToSign : gradeToExec;
		throw GradeTooLowException(gradeToThrow, ERRMSG);
	}
}

AForm::AForm(const AForm& other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
	this->operator=(other);
}

AForm::~AForm() {};

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

std::runtime_error	AForm::GradeTooHighException(int grade, std::string errMsg) const
{
	std::stringstream ss;

	ss << grade;
	std::string gradeStr = ss.str();
	return std::runtime_error(
		std::string("grade(") +
		gradeStr +
		std::string(") is too high!\n") +
		errMsg
	);
}

std::runtime_error	AForm::GradeTooLowException(int grade, std::string errMsg) const
{
	std::stringstream ss;

	ss << grade;
	std::string gradeStr = ss.str();
	return std::runtime_error(
		std::string("grade(") +
		gradeStr +
		std::string(") is too low!\n") +
		errMsg
	);
}

bool	AForm::_isGradeTooHigh(const int& grade) const
{
	return (grade < highestGrade);
}

bool	AForm::_isGradeTooLow(const int& grade) const
{
	return (grade > lowestGrade);
}

const std::string	AForm::getName() const
{
	return _name;
}

const int&	AForm::getGradeToSign() const
{
	return _gradeToSign;
}

const int&	AForm::getGradeToExec() const
{
	return _gradeToExec;
}

const bool&	AForm::getIsSigned() const
{
	return _isSigned;
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw GradeTooLowException(b.getGrade(), "");
	this->_isSigned = true;
	std::cout << b.getName() << " signed " << this->_name << '\n';
}

std::ostream&	operator<<(std::ostream& os, const AForm &obj)
{
	const std::string isSigned = obj.getIsSigned() ? "signed" : "not signed";

	os << obj.getName() << ", status " << isSigned << ", the bureaucrat grade to sign "
		<< obj.getGradeToSign() << ", the bureaucrat grade to execute " << obj.getGradeToExec() << ".\n";
	return os;
}
