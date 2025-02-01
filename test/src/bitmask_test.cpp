#include "gtest/gtest.h"

#include "bitmask.hpp"

namespace
{
    enum Enum : unsigned char
    {
        FirstValue,
        SecondValue,
        ThirdValue,
        MaxValue
    };

    enum StronglyTypedEnum : unsigned char
    {
        stFirstValue,
        stSecondValue,
        stThirdValue,
        stMaxValue
    };

    TEST(BitMaskTest, DefaultCtor)
    {
        BitMask<Enum, Enum::MaxValue> en;
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> stEn;

        EXPECT_EQ(en.value(), 0);
        EXPECT_EQ(stEn.value(), 0);
    }

    TEST(BitMaskTest, ParameterPackCtor)
    {
        BitMask<Enum, Enum::MaxValue> en(Enum::FirstValue, Enum::SecondValue);
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> stEn(StronglyTypedEnum::stFirstValue, StronglyTypedEnum::stSecondValue);

        EXPECT_EQ(en.value(), 0b00000011);
        EXPECT_EQ(stEn.value(), 0b00000011);
    }

    TEST(BitMaskTest, ValueCtor)
    {
        BitMask<Enum, Enum::MaxValue> en(0b00000101);
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> stEn(0b00000011);

        //правильно сохранили то, что передали
        EXPECT_EQ(en.value(), 0b00000101);
        EXPECT_EQ(stEn.value(), 0b00000011);

        //контейнер с лишним битом, не поддерживаемым перечислением
        BitMask<Enum, Enum::MaxValue> en2(0b10010101);
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> stEn2(0b11100111);

        //в результате лишние биты должны пропасть
        EXPECT_EQ(en2.value(), 0b00000101);
        EXPECT_EQ(stEn2.value(), 0b00000111);
    }
}