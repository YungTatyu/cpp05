#ifndef ROBOTMONYREQUESTFORM_HPP
#define ROBOTMONYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string	_target;
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& name, const int& gradeToSign, const int& gradeToExec);
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
	void	execute(Bureaucrat const& executor) const;
	static const std::string	name;
	static const int	gradeToSign = 72;
	static const int	gradeToExec = 45;
};

#endif