#include <gtest/gtest.h>
#include "Bureaucrat.hpp"

TEST(isEvenTest, Negative) {
    EXPECT_FALSE(isEven(-1));
    EXPECT_TRUE(isEven(-2));
}

TEST(isEvenTest, Zero) {
    EXPECT_TRUE(isEven(0));
}

TEST(isEvenTest, Positive) {
    EXPECT_FALSE(isEven(1));
    EXPECT_TRUE(isEven(2));
}