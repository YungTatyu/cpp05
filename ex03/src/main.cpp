#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	const std::string	name = "b";
	const Bureaucrat	b(name, 1);
	const std::string	target = "home";
	Intern	intern;
	AForm	*form = intern.makeForm("RobotomyRequestForm", target);

	b.signForm(*form);

	return 0;
}