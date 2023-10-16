#include "Bureaucrat.hpp"

int	main()
{
	{
		std::string name = "b";
		int	grade = 1;
		try
		{
			Bureaucrat	b(name, grade);
			b.incrementGrade();
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
			b.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
	}


	return 0;
}