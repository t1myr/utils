#include "gtest/gtest.h"
#include <string>
#include "optional.hpp"
#include <optional>

struct TestClass
{
    TestClass()
    {
        std::cout << "Default ctor call" << std::endl;
    }

    TestClass(int a, int b, int c) : a(a), b(b), c(c)
    {
        std::cout << "Full ctor call" << std::endl;
    }

    TestClass(TestClass&& cl) : a(cl.a), b(cl.b), c(cl.c)
    {
        std::cout << "Move ctor" << std::endl;
    }

    TestClass(const TestClass& cl) : a(cl.a), b(cl.b), c(cl.c)
    {
        std::cout << "Copy ctor" << std::endl;
    }

    int a{0};
    int b{1};
    int c{2};
};

TEST(OptionalTest, DefaultCtor)
{
    optional<TestClass> opt;
    TestClass cl;
    opt.emplace();
    opt.emplace(TestClass());
    opt.emplace(cl);

    EXPECT_EQ(opt->a, 0);
    EXPECT_EQ(opt->b, 1);
    EXPECT_EQ(opt->c, 2);
}