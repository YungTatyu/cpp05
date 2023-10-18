#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <vector>

TEST(Bureaucrat_signFormTest, Grade_Low) {

	const std::string	b_name = "b";
	const int	b_grade = 150;
	Bureaucrat	b(b_name, b_grade);

	const std::string	f_name = "f";
	const int	f_grade = 15;
	Form	f(f_name, f_grade, 1);

	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	b.signForm(f);
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ("", stdoutOutput);
	EXPECT_EQ(
		b_name +
		std::string(" couldn’t sign ") +
		f_name +
		std::string(" because ") +
		b_name +
		std::string(" doesn't meet the required grade.\n"),
		stderrOutput
	);
}

TEST(Bureaucrat_signFormTest, Grade_Pass) {

	std::vector<int> v = {1, 14, 15, 16};
	const int	f_grade = 16;

	for (auto it = v.begin(); it != v.end(); it++)
	{
		const std::string	b_name = "b";
		Bureaucrat	b(b_name, *it);

		const std::string	f_name = "f";
		Form	f(f_name, f_grade, 1);

		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();

		b.signForm(f);
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ(b_name + " signed " + f_name + "\n", stdoutOutput);
		EXPECT_EQ("", stderrOutput);
	}
}
