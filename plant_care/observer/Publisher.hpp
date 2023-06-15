#pragma once

#include "IPublisher.hpp"

#include <functional>
#include <list>

class Publisher : public IPublisher
{
public:
    virtual ~Publisher() = default;

    void subscribe(IObserver &observer) override;

    void unsubscribe(IObserver &observer) override;

    void unsubscribeAll() override;

    void notify(boost::any const &data) override;

private:
    using IObserverRef = std::reference_wrapper<IObserver>;

    std::list<IObserverRef> m_observers;
};
