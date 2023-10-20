#ifndef SHRUBBERYCREATION_HPP
#define SHRUBBERYCREATION_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_target;
	ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	void	execute(Bureaucrat const& executor) const;
	static const std::string	name;
	static const int	gradeToSign = 145;
	static const int	gradeToExec = 137;
};


#endif