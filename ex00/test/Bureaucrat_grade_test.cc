#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "Bureaucrat.hpp"

// 第1引数がテストケース名、第2引数がテスト名
TEST(Bureaucrat_gradeTest, High) {
	std::string name = "b";
	int	grade = 0;
	std::stringstream ss;
	ss << grade;
	std::string gradeStr = ss.str();

	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	EXPECT_THROW(
		{
			Bureaucrat	b(name, grade);
		},
		std::runtime_error
	);
	try {
			Bureaucrat	b(name, grade);
	}
	catch (const std::exception& e)
	{
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ("", stdoutOutput);
		EXPECT_EQ("", stderrOutput);
		EXPECT_EQ(
			std::string("grade ") +
			gradeStr +
			std::string(" is too high!\n") +
			std::string("possible grade is between 1 to 150\n"),
			e.what()
		);
	}
}
