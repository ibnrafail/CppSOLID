#pragma once

#include "IObserver.hpp"

class IPublisher
{
public:
    virtual ~IPublisher() = default;

    virtual void subscribe(IObserver &observer) = 0;

    virtual void unsubscribe(IObserver &observer) = 0;

    virtual void notify(boost::any const &data) = 0;
};
