#pragma once

#include <boost/any.hpp>

class IObserver
{
public:
    virtual ~IObserver() = default;

    virtual void update(boost::any const &data) = 0;

    friend bool operator==(const IObserver &lhs, const IObserver &rhs)
    {
        return std::addressof(lhs) == std::addressof(rhs);
    }

    friend bool operator!=(const IObserver &lhs, const IObserver &rhs)
    {
        return !(lhs == rhs);
    }
};
