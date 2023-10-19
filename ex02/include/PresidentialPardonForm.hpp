#ifndef PRESIDENTPARDONFORM_HPP
#define PRESIDENTPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string	_target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
	void	execute(Bureaucrat const& executor) const;
	static const int	gradeToSign = 72;
	static const int	gradeToExec = 45;
};


#endif