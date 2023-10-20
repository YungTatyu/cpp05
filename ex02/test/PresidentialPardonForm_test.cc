#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"


TEST(PresidentialPardonForm_ExecuteTest, Pass) {

	for (int i = PresidentialPardonForm::gradeToExec; i >= Bureaucrat::highestGrade; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const Bureaucrat	b2(name, 1);
		const std::string	target = "home";

		PresidentialPardonForm	f(target);
		b2.signForm(f);
		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		EXPECT_NO_THROW(
			{
				f.execute(b);
			}
		);
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ(target + " is pardoned by Zaphod Beeblebrox\n", stdoutOutput);
		EXPECT_EQ("", stderrOutput);
	}
}

TEST(PresidentialPardonForm_ExecuteTest, NoSign) {

	for (int i = PresidentialPardonForm::gradeToExec; i >= Bureaucrat::highestGrade; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const Bureaucrat	b2(name, 1);
		const std::string	target = "home";

		PresidentialPardonForm	f(target);
		b2.signForm(f);

		EXPECT_THROW(
			{
				f.execute(b);
			},
			std::runtime_error
		);


		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		try
		{
			f.execute(b);
		}
		catch(const std::exception& e)
		{
			std::string stdoutOutput = testing::internal::GetCapturedStdout();
			std::string stderrOutput = testing::internal::GetCapturedStderr();
			EXPECT_EQ("", stdoutOutput);
			EXPECT_EQ("", stderrOutput);
			EXPECT_EQ(target + " doesn't have a sign on it so can't execute.\n", e.what());
		}
	}
}

TEST(PresidentialPardonForm_ExecuteTest, LowGrade) {

	for (int i = Bureaucrat::lowestGrade; i >= PresidentialPardonForm::gradeToExec; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const Bureaucrat	b2(name, 1);
		const std::string	target = "home";

		PresidentialPardonForm	f(target);
		b2.signForm(f);

		EXPECT_THROW(
			{
				f.execute(b);
			},
			std::runtime_error
		);


		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		try
		{
			f.execute(b);
		}
		catch(const std::exception& e)
		{
			std::string stdoutOutput = testing::internal::GetCapturedStdout();
			std::string stderrOutput = testing::internal::GetCapturedStderr();
			EXPECT_EQ("", stdoutOutput);
			EXPECT_EQ("", stderrOutput);
			EXPECT_EQ(name + " doesn't meet the required grade.\n", e.what());
		}
	}
}
