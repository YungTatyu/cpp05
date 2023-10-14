#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

int	isEven(int n);

class Bureaucrat
{
private:
	const std::string	_name;
	int	_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat &obj);
	const std::string&	getName() const;
	const int&	getGrade() const;
};

#endif