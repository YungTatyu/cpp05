#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"

// 第1引数がテストケース名、第2引数がテスト名
TEST(Form_gradeToSignTest, init_High) {
	for (int grade = -100; grade < (Form::highestGrade - 1); grade++)
	{
		const std::string name = "f";
		const std::string gradeToExec_str = "1";
		const int	gradeToExec = 1;

		std::stringstream ss;
		ss << grade;
		std::string gradeStr = ss.str();

		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		EXPECT_THROW(
			{
				Form	f(name, grade, gradeToExec);
			},
			std::runtime_error
		);
		try
		{
			Form	f(name, grade, gradeToExec);
		}
		catch (const std::exception& e)
		{
			std::string stdoutOutput = testing::internal::GetCapturedStdout();
			std::string stderrOutput = testing::internal::GetCapturedStderr();
			EXPECT_EQ("", stdoutOutput);
			EXPECT_EQ("", stderrOutput);
			EXPECT_EQ(
				std::string("grade to sign(") +
				gradeStr +
				std::string(") is too high!\n") +
				std::string("possible grade is between 1 to 150\n"),
				e.what()
			);
		}
	}
}

TEST(Form_gradeToSignTest, init_Low) {
	for (int grade = (Form::lowestGrade + 1); grade < 250; grade++)
	{
		const std::string name = "f";
		const std::string gradeToExec_str = "1";
		const int	gradeToExec = 1;

		std::stringstream ss;
		ss << grade;
		std::string gradeStr = ss.str();

		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		EXPECT_THROW(
			{
				Form	f(name, grade, gradeToExec);
			},
			std::runtime_error
		);
		try
		{
			Form	f(name, grade, gradeToExec);
		}
		catch (const std::exception& e)
		{
			std::string stdoutOutput = testing::internal::GetCapturedStdout();
			std::string stderrOutput = testing::internal::GetCapturedStderr();
			EXPECT_EQ("", stdoutOutput);
			EXPECT_EQ("", stderrOutput);
			EXPECT_EQ(
				std::string("grade to sign(") +
				gradeStr +
				std::string(") is too low!\n") +
				std::string("possible grade is between 1 to 150\n"),
				e.what()
			);
		}
	}
}

TEST(Bureaucrat_gradeTest, init_Pass) {
	for (int grade = Form::highestGrade; grade < (Form::lowestGrade + 1); grade++)
	{
		const std::string name = "f";
		const std::string gradeToExec_str = "1";
		const int	gradeToExec = 1;

		std::stringstream ss;
		ss << grade;
		std::string gradeStr = ss.str();

		EXPECT_NO_THROW(
			{
				Form	f(name, grade, gradeToExec);
			}
		);
	}
}
