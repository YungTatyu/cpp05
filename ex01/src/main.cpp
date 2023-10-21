#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	{
		std::string name = "b";
		int	grade = 1;
		try
		{
			Bureaucrat	b(name, grade);
			Form	f("file", 10, 1);
			b.signForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	{
		std::string name = "b";
		int	grade = 150;
		try
		{
			Bureaucrat	b(name, grade);
			Form	f("file", 10, 1);
			b.signForm(f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}


	return 0;
}