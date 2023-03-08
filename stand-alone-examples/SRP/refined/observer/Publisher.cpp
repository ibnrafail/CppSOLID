#include "Publisher.hpp"

void Publisher::subscribe(IObserver &observer)
{
    m_observers.emplace_back(IObserverRef(observer));
}

void Publisher::unsubscribe(IObserver &observer)
{
    m_observers.remove(IObserverRef(observer));
}

void Publisher::notify(boost::any const &data)
{
    for (auto observer : m_observers)
    {
        observer.get().update(data);
    }
}

std::list<Publisher::IObserverRef> &Publisher::GetObservers()
{
    return m_observers;
}