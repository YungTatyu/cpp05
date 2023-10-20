#include <gtest/gtest.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <sstream>
#include <string>
#include <vector>

TEST(Form_operatorTest, insertion) {
	std::string name = "f";
	int	gradeToSign = 2;
	int	gradeToExec = 2;
	std::vector<int> v = {1 , 2};


	for (auto it = v.begin(); it != v.end(); it++)
	{
		Form	f(name, gradeToSign, gradeToExec);
		Bureaucrat	b(name, 1);
		if (*it % 2 == 0)
			b.signForm(f);
		std::string isSigned = f.getIsSigned() ? "signed" : "not signed";
		std::stringstream ss;
		ss << gradeToSign;
		std::string gradeToSignStr = ss.str();
		ss.str("");
		ss << gradeToExec;
		std::string gradeToExecStr = ss.str();

		testing::internal::CaptureStdout();
		testing::internal::CaptureStderr();
		std::cout << f;
		std::string stdoutOutput = testing::internal::GetCapturedStdout();
		std::string stderrOutput = testing::internal::GetCapturedStderr();
		EXPECT_EQ(
			stdoutOutput,
			name + std::string(", status ") + isSigned +
			std::string(", the bureaucrat grade to sign ") +
			gradeToSignStr +
			std::string(", the bureaucrat grade to execute ") +
			gradeToExecStr +
			std::string(".\n")
		);
		EXPECT_EQ("", stderrOutput);
	}

}