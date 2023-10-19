#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include <vector>
#include <fstream>
#include <filesystem>

bool	_deleteFile(const std::string& filename)
{
	try
	{
		std::filesystem::remove(filename);
	}
	catch(const std::filesystem::filesystem_error& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}
	return true;
}

// 第1引数がテストケース名、第2引数がテスト名
TEST(ShrubberyCreationForm_ExecuteTest, Pass) {

	const std::string content = R"(
		 v
        >X<
         A
        d$b
      .d\$$b.
    .d$i$$\$$b.
       d$$@b
      d\$$$ib
    .d$$$\$$$b
  .d$$@$$$$\$$ib.
      d$$i$$b
     d\$$$$@$b
  .d$@$$\$$$$$@b.
.d$$$$i$$$\$$$$$$b.
        ###
        ###
        ### mh
)";
	for (int i = ShrubberyCreationForm::gradeToExec; i >= Bureaucrat::highestGrade; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const Bureaucrat	b2(name, 1);
		const std::string	target = "home";
		const std::string	filename = target + "_shrubbery";

		ShrubberyCreationForm	f(target);
		b2.signForm(f);

		if (!_deleteFile(filename))
			FAIL() << "error: failed to remove a file\n";
		EXPECT_NO_THROW(
			{
				f.execute(b);
			}
		);
		std::ifstream	file(filename);
		std::stringstream	buffer;
		if (!file.is_open())
			FAIL() << "error: failed to open a file\n";
		buffer << file.rdbuf();
		EXPECT_EQ(buffer.str(), content);
		if (!_deleteFile(filename))
			FAIL() << "error: failed to remove a file\n";
	}
}

TEST(ShrubberyCreationForm_ExecuteTest, LowGrade) {

	for (int i = Bureaucrat::lowestGrade; i >= ShrubberyCreationForm::gradeToExec; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const Bureaucrat	b2(name, 1);
		const std::string	target = "home";
		ShrubberyCreationForm	f(target);
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


// 第1引数がテストケース名、第2引数がテスト名
TEST(ShrubberyCreationForm_ExecuteTest, NoSign) {

	const std::string content = R"(
		 v
        >X<
         A
        d$b
      .d\$$b.
    .d$i$$\$$b.
       d$$@b
      d\$$$ib
    .d$$$\$$$b
  .d$$@$$$$\$$ib.
      d$$i$$b
     d\$$$$@$b
  .d$@$$\$$$$$@b.
.d$$$$i$$$\$$$$$$b.
        ###
        ###
        ### mh
)";
	for (int i = ShrubberyCreationForm::gradeToExec; i >= Bureaucrat::highestGrade; i--)
	{
		const std::string	name = "b";
		const Bureaucrat	b(name, i);
		const std::string	target = "home";
		const std::string	filename = target + "_shrubbery";

		ShrubberyCreationForm	f(target);

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
