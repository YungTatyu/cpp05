#include "Intern.hpp"

const int	Intern::totalFunctions;
const char*	Intern::validFormNames[Intern::totalFunctions] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

Intern::Intern()
{
	FormMaker[0] = Intern::_makeShrubberyCreationForm;
	FormMaker[1] = Intern::_makeRobotomyRequestForm;
	FormMaker[2] = Intern::_makePresidentialPardonForm;
}

Intern::~Intern() {}

AForm	*Intern::_makeShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::_makeRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::_makePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const std::string& formName, const std::string& target) const
{
	for (size_t i = 0; i < totalFunctions; i++)
	{
		if (formName == validFormNames[i])
			return (this->FormMaker[i])(target);
	}
	std::cerr << formName + ": No such file exists\n";
	return NULL;
}
