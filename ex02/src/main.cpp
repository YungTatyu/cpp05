#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	{
		std::string name = "b";
		int	grade = 1;
		Bureaucrat	b(name, grade);
		try
		{
			PresidentialPardonForm	f("home");
			b.signForm(f);
			b.executeForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	{
		std::string name = "b";
		int	grade = 150;
		Bureaucrat	b(name, grade);
		try
		{
			PresidentialPardonForm	f("home");
			b.signForm(f);
			b.executeForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}


	return 0;
}