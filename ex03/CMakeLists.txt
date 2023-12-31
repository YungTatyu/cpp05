cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++98
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  mytest
  test/Bureaucrat_operator_test.cc
  test/Bureaucrat_grade_test.cc
  test/Bureaucrat_grade_test.cc
  # test/Bureaucrat_signForm_test.cc
  # test/Form_gradeToExec_test.cc
  # test/Form_gradeToSign_test.cc
  # test/Form_operator_test.cc
  test/PresidentialPardonForm_test.cc
  test/RobotomyRequestForm_test.cc
  test/ShrubberyCreationForm_test.cc
  test/Bureaucrat_executeForm_test.cc
  test/Intern_test.cc
  src/Bureaucrat.cpp
  src/PresidentialPardonForm.cpp
  src/RobotomyRequestForm.cpp
  src/ShrubberyCreationForm.cpp
  src/AForm.cpp
  src/Intern.cpp
)

include_directories(
  mytest
  include
)

target_link_libraries(
  mytest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mytest)
