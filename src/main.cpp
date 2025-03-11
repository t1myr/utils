#include <iostream>
#include <cstdint>
#include "bitset.hpp"
#include "bitmask.hpp"
#include "optional.hpp"
#include "bimap.hpp"
#include "my_exception.hpp"

enum PowerMode : unsigned char
{
    None,
    On,
    Off,
    MaxValue,
};

enum class Color : unsigned char
{
    Red,
    Green,
    Blue,
    MaxValue,
};

enum Suit : int
{ 
    Diamonds, 
    Hearts, 
    Clubs, 
    Spades
};

void func()
{
    throw MyException(1, source_location::current());
}

int main()
{    
    BitMask<PowerMode, PowerMode::MaxValue> pwrMode;
    BitMask<Color, static_cast<unsigned char>(Color::MaxValue)> color;
    // BitMask<Suit, 8> suit;
    BitSet<uint8_t, 8> mask;
    optional<int> opt;
    std::cout << "Hello, world!" << std::endl;
    try
    {
        func();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}