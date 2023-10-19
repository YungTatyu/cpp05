#ifndef SHRUBBERYCREATION_HPP
#define SHRUBBERYCREATION_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
	void	execute(Bureaucrat const& executor) const;
	static const int	gradeToSign = 145;
	static const int	gradeToExec = 137;
};


#endif