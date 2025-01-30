#pragma once

#include <set>


template<class LeftKey, typename RightKey>
struct bimap
{
    constexpr bimap_base() = default;

    constexpr bimap_base(std::initializer_list<std::pair<LeftKey, RightKey>> _list) noexcept
    {
        for (auto& elem : _list)
        {

        }
    }

private:
    std::set<std::pair<LeftKey, RightKey*>> _keyValueContainer;
    std::set<std::pair<LeftKey*, RightKey>> _valueKeyContainer;
};
