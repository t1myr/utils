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

    TEST(BitMaskTest, InitListAssignOperator)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000011);

        //сбрасываем значение
        en = {};

        EXPECT_EQ(en.value(), 0b00000000);

        //задаем первые три
        en = {StronglyTypedEnum::stFirstValue, StronglyTypedEnum::stSecondValue,
                                                StronglyTypedEnum::stThirdValue};

        EXPECT_EQ(en.value(), 0b00000111);
    }

    TEST(BitMaskTest, ValueOperator)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000111);

        uint8_t value = en;

        EXPECT_EQ(value, 0b00000111);
    }

    TEST(BitMaskTest, PlusOperator)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000101);

        auto newEn = en + StronglyTypedEnum::stSecondValue;

        EXPECT_EQ((int)newEn.value(), 0b00000111);
    }

    TEST(BitMaskTest, MinusOperator)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000101);

        auto newEn = en - StronglyTypedEnum::stFirstValue;

        EXPECT_EQ((int)newEn.value(), 0b00000100);
    }

    TEST(BitMaskTest, PlusEqualsOperator)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000101);

        en += StronglyTypedEnum::stSecondValue;

        EXPECT_EQ((int)en.value(), 0b00000111);
    }

    TEST(BitMaskTest, MinusEqualsOperator)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000101);

        en -= StronglyTypedEnum::stFirstValue;

        EXPECT_EQ((int)en.value(), 0b00000100);
    }

    TEST(BitMaskTest, Has)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000101);

         BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> enInner(0b00000001);


        EXPECT_TRUE(en.has(StronglyTypedEnum::stFirstValue, StronglyTypedEnum::stThirdValue));

        EXPECT_TRUE(en.has(enInner));
    }

    TEST(BitMaskTest, Any)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000000);

        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en2(0b00000001);

        EXPECT_FALSE(en.any());

        EXPECT_TRUE(en2.any());
    }

    TEST(BitMaskTest, AllAndEmpty)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000111);

        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en2(0b00000010);

        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> enEmpty(0b00000000);

        EXPECT_FALSE(en2.all());

        EXPECT_TRUE(en.all());

        EXPECT_FALSE(en.empty());

        EXPECT_TRUE(enEmpty.empty());
    }

    TEST(BitMaskTest, Set)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000000);

        en.set(StronglyTypedEnum::stFirstValue);

        EXPECT_EQ(en.value(), 0b00000001);
    }

    TEST(BitMaskTest, Reset)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000111);

        en.reset(StronglyTypedEnum::stFirstValue);

        EXPECT_EQ(en.value(), 0b00000110);

        en.reset();

        EXPECT_EQ(en.value(), 0b00000000);
    }

    TEST(BitMaskTest, Count)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000111);

        EXPECT_EQ(en.count(), 3);
    }

    TEST(BitMaskTest, ToString)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000111);

        EXPECT_STREQ(en.to_string().c_str(), "00000111");
    }

    TEST(BitMaskTest, At)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000000);

        {
            const auto bit = en.at(StronglyTypedEnum::stFirstValue);

            EXPECT_FALSE(bit); 
        }
        
        {
            auto bit = en.at(StronglyTypedEnum::stFirstValue);

            bit = 1;

            EXPECT_TRUE(bit); 

            EXPECT_EQ(en.value(), 0b00000001); 

            en.at(StronglyTypedEnum::stFirstValue) = 0;

            EXPECT_EQ(en.value(), 0b00000000); 
        }
    }

    TEST(BitMaskTest, SquareBrackets)
    {
        BitMask<StronglyTypedEnum, StronglyTypedEnum::stMaxValue> en(0b00000000);

        {
            const auto bit = en[StronglyTypedEnum::stFirstValue];

            EXPECT_FALSE(bit); 
        }
        
        {
            auto bit = en[StronglyTypedEnum::stFirstValue];

            bit = 1;

            EXPECT_TRUE(bit); 

            EXPECT_EQ(en.value(), 0b00000001); 

            en[StronglyTypedEnum::stFirstValue] = 0;

            EXPECT_EQ(en.value(), 0b00000000); 
        }
    }
}
