#pragma once

#include <functional>
#include <list>

#include "TempObserver.hpp"

template <typename NotificationData>
class TempPublisher
{
public:
    virtual ~TempPublisher() = default;

    void subscribe(TempObserver<NotificationData> &observer)
    {
        m_observers.emplace_back(ObserverRef(observer));
    }

    void unsubscribe(TempObserver<NotificationData> &observer)
    {
        m_observers.remove(ObserverRef(observer));
    }

    void unsubscribeAll()
    {
        m_observers.clear();
    }

    void notify(NotificationData const &data)
    {
        for (auto observer : m_observers)
        {
            observer.get().update(data);
        }
    }

private:
    using ObserverRef = std::reference_wrapper<TempObserver<NotificationData>>;

    std::list<ObserverRef> m_observers;
};
