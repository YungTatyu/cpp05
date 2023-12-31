#ifndef PRESIDENTPARDONFORM_HPP
#define PRESIDENTPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string	_target;
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& name, const int& gradeToSign, const int& gradeToExec);
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	void	execute(Bureaucrat const& executor) const;
	static const std::string	name;
	static const int	gradeToSign = 25;
	static const int	gradeToExec = 5;
};


#endif