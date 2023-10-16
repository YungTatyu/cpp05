#include "Bureaucrat.hpp"

int	main()
{
	std::string name = "b";
	int	grade = 0;
	try
	{
		Bureaucrat	b(name, grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}