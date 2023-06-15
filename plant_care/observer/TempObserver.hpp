#pragma once

#include <memory>

template<typename NotificationData>
class TempObserver
{
public:
    virtual ~TempObserver() = default;

    virtual void update(NotificationData const &data) = 0;

    friend bool operator==(const TempObserver &lhs, const TempObserver &rhs)
    {
        return std::addressof(lhs) == std::addressof(rhs);
    }

    friend bool operator!=(const TempObserver &lhs, const TempObserver &rhs)
    {
        return !(lhs == rhs);
    }
};
