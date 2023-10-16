#include <gtest/gtest.h>
#include "Bureaucrat.hpp"
#include <sstream>
#include <string>

TEST(Bureaucrat_operatorTest, insertion) {
	std::string name = "b";
	int	grade = 1;
	Bureaucrat	b(name, grade);
	std::stringstream ss;
	ss << grade;
	std::string gradeStr = ss.str();

	testing::internal::CaptureStdout();
	testing::internal::CaptureStderr();
	std::cout << b;
	std::string stdoutOutput = testing::internal::GetCapturedStdout();
	std::string stderrOutput = testing::internal::GetCapturedStderr();
	EXPECT_EQ(
		stdoutOutput,
		name + std::string(", bureaucrat grade ") +
		gradeStr +
		std::string(".\n")
	);
	EXPECT_EQ("", stderrOutput);
}