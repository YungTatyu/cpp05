#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

bool	deleteFile(const std::string& filename);


static void	_expectSuccess(const Bureaucrat& b, const AForm& f)
{
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();

	b.executeForm(f);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(b.getName() + " executed " + f.getName() + "\n",  stdoutOutput);
	EXPECT_EQ("",  stderrOutput);
}

static void	_expectFail(const Bureaucrat& b, const AForm& f)
{
	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();

	b.executeForm(f);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ("",  stdoutOutput);
	EXPECT_TRUE(stderrOutput);
}

TEST(Bureaucrat_ExecuteTest, All) {

	for (int i = Bureaucrat::lowestGrade; i >= Bureaucrat::highestGrade; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const Bureaucrat	b_sign(name, 1);
		const std::string	target = "home";
		const std::string	filename = target + "_shrubbery";

		const ShrubberyCreationForm	scf(target);
		const RobotomyRequestForm	rrf(target);
		const PresidentialPardonForm	ppf(target);

		//sign all form
		b_sign.signForm(scf);
		b_sign.signForm(rrf);
		b_sign.signForm(ppf);

		if (!deleteFile(filename))
			FAIL() << "error: failed to remove a file\n";

		/* ShrubberyCreationFormのtest */
		if (i <= ShrubberyCreationForm::gradeToExec)
		{
			_expectSuccess(b, scf);
			if (!deleteFile(filename))
				FAIL() << "error: failed to remove a file\n";
		}
		else
			_expectFail(b, scf);

		/* RobotomyRequestFormのtest */
		if (i <= RobotomyRequestForm::gradeToExec)
			_expectSuccess(b, rrf);
		else
			_expectFail(b, rrf);

		/* PresidentialPardonFormのtest */
		if (i <= PresidentialPardonForm::gradeToExec)
			_expectSuccess(b, ppf);
		else
			_expectFail(b, ppf);
	}
}
