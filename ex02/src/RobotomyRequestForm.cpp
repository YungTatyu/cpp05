#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

#define DRILLING_NOISES "Buzzing, buzzing, buzzing...\n"
#define EXEC_SUCCESS "robotomy successed!\n"
#define EXEC_FAIL "robotomy failed :(\n"

const int	RobotomyRequestForm::gradeToSign;
const int	RobotomyRequestForm::gradeToExec;
const std::string	RobotomyRequestForm::name = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(name, RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExec), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(name, RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExec), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	const bool	isSigned = getIsSigned();
	std::string errorMsg;

	if (getGradeToExec() < RobotomyRequestForm::gradeToExec || isSigned == false)
	{
		if (isSigned == false)
			errorMsg = getName() + " doesn't have a sign on it so can't execute.\n";
		else
			errorMsg = executor.getName() + " doesn't meet the required grade.\n";
		throw std::runtime_error(errorMsg);
	}
	std::srand(std::time(0));
	int	randomNum = std::rand();
	std::cout << DRILLING_NOISES;
	if (randomNum % 2 == 0)
		std::cout << EXEC_SUCCESS;
	else
		std::cout << EXEC_FAIL;
}
