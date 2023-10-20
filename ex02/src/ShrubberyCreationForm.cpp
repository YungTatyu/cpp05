#include "ShrubberyCreationForm.hpp"
#include <fstream>
#define FILENAME "_shrubbery"

const int	ShrubberyCreationForm::gradeToSign;
const int	ShrubberyCreationForm::gradeToExec;
const std::string	ShrubberyCreationForm::name = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(name, ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExec), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(name, ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExec), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	const bool	isSigned = getIsSigned();
	std::string errorMsg;

	if (getGradeToExec() < ShrubberyCreationForm::gradeToExec || isSigned == false)
	{
		if (isSigned == false)
			errorMsg = getName() + " doesn't have a sign on it so can't execute.\n";
		else
			errorMsg = executor.getName() + " doesn't meet the required grade.\n";
		throw std::runtime_error(errorMsg);
	}

	std::ofstream	file(_target + FILENAME);
	if (!file)
		throw std::ios_base::failure("failed to open a file " + _target + FILENAME);

	const std::string content = "\
		 v\
        >X<\
         A\
        d$b\
      .d\\$$b.\
    .d$i$$\\$$b.\
       d$$@b\
      d\\$$$ib\
    .d$$$\\$$$b\
  .d$$@$$$$\\$$ib.\
      d$$i$$b\
     d\\$$$$@$b\
  .d$@$$\\$$$$$@b.\
.d$$$$i$$$\\$$$$$$b.\
        ###\
        ###\
        ### mh\
";

	file << content << std::flush;
}
