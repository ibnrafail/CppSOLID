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

    void notify(boost::any const &data) override;

protected:
    using IObserverRef = std::reference_wrapper<IObserver>;

    std::list<IObserverRef> &GetObservers();

private:
    std::list<IObserverRef> m_observers;
};
