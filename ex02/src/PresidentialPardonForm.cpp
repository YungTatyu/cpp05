#include "PresidentialPardonForm.hpp"
#include <fstream>
#define EXEC_MSG " is pardoned by Zaphod Beeblebrox\n"

const int	PresidentialPardonForm::gradeToSign;
const int	PresidentialPardonForm::gradeToExec;
const std::string	PresidentialPardonForm::name = "PresidentialPardonForm";

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm(name, PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExec), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(name, PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExec), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}


PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	AForm::operator=(other);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	const bool	isSigned = getIsSigned();
	std::string errorMsg;

	if (executor.getGrade() > PresidentialPardonForm::gradeToExec || isSigned == false)
	{
		if (isSigned == false)
			errorMsg = getName() + " doesn't have a sign on it so can't execute.\n";
		else
			errorMsg = executor.getName() + " doesn't meet the required grade.\n";
		throw std::runtime_error(errorMsg);
	}
	std::cout << _target + EXEC_MSG;
}
