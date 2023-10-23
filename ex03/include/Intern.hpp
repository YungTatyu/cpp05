#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	static AForm	*_makeShrubberyCreationForm(const std::string& target);
	static AForm	*_makeRobotomyRequestForm(const std::string& target);
	static AForm	*_makePresidentialPardonForm(const std::string& target);
	const static int	totalFunctions = 3;
	const static char*	validFormNames[totalFunctions];
	AForm	*(*FormMaker[totalFunctions])(const std::string& target);

public:
	Intern();
	~Intern();
	AForm	*makeForm(const std::string& formName, const std::string& target) const;
};

#endif