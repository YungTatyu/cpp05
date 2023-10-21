#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

bool	deleteFile(const std::string& filename);

void	_execInternTest(const Bureaucrat& b, const std::string& formName, const std::string& target)
{
	Intern	intern;
	AForm	*form = intern.makeForm(formName, target);

	b.signForm(*form);
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	b.executeForm(*form);

	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	if (stdoutOutput.find("executed") == std::string::npos)
			FAIL() << "no execution found!\n";
	EXPECT_EQ("",  stderrOutput);
}

TEST(Intern_makeFormTest, ShrubberyCreationForm) {
	const std::string	name = "b";
	const Bureaucrat	b(name, 1);
	const std::string	target = "home";
	const Intern	intern;
	const std::string	filename = target + "_shrubbery";

	_execInternTest(b, "ShrubberyCreationForm", target);
	if (!deleteFile(filename))
		FAIL() << "error: failed to remove a file\n";
}

TEST(Intern_makeFormTest, PresidentialPardonForm) {
	const std::string	name = "b";
	const Bureaucrat	b(name, 1);
	const std::string	target = "home";
	const Intern	intern;

	_execInternTest(b, "PresidentialPardonForm", target);
}

TEST(Intern_makeFormTest, RobotomyRequestForm) {
	const std::string	name = "b";
	const Bureaucrat	b(name, 1);
	const std::string	target = "home";

	_execInternTest(b, "RobotomyRequestForm", target);
}

TEST(Intern_makeFormTest, Fail) {
	const std::string	name = "b";
	const std::string	target = "home";
	const std::string	file = "no exist file";
	Intern	intern;

	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	AForm	*form = intern.makeForm(file, target);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();

	EXPECT_EQ("", stdoutOutput);
	EXPECT_EQ(file + ": No such file exists\n", stderrOutput);
	EXPECT_EQ(NULL, form);

}