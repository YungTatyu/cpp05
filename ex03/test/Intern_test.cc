#include <gtest/gtest.h>
#include <gtest/internal/gtest-port.h>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

TEST(Intern_makeFormTest, ShrubberyCreationForm) {
	const std::string	name = "b";
	const Bureaucrat	b(name, 1);
	const std::string	target = "home";
}
