#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

TEST(RobotomyRequestForm_ExecuteTest, Pass) {
	for (int i = RobotomyRequestForm::gradeToExec; i >= Bureaucrat::highestGrade; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const Bureaucrat	b2(name, 1);
		const std::string	target = "home";

		RobotomyRequestForm	f(target);
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
		EXPECT_EQ("", stderrOutput);
		if (stdoutOutput.find("Buzzing, buzzing, buzzing...\n") == std::string::npos)
			FAIL() << "doesn't make drilling noises\n";
		if (stdoutOutput.find("successed") == std::string::npos &&
			stdoutOutput.find("failed") == std::string::npos)
			FAIL() << "doesn't have any stdoutput\n";
	}
}

TEST(RobotomyRequestForm_ExecuteTest, NoSign) {
	for (int i = RobotomyRequestForm::gradeToExec; i >= Bureaucrat::highestGrade; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const Bureaucrat	b2(name, 1);
		const std::string	target = "home";

		RobotomyRequestForm	f(target);

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
			EXPECT_EQ(f.getName() + " doesn't have a sign on it so can't execute.\n", e.what());
		}
	}
}

TEST(RobotomyRequestForm_ExecuteTest, LowGrade) {

	for (int i = Bureaucrat::lowestGrade; i > RobotomyRequestForm::gradeToExec; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const Bureaucrat	b2(name, 1);
		const std::string	target = "home";

		RobotomyRequestForm	f(target);
		b2.signForm(f);
		std::clearerr(stdin);
		std::cin;

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
