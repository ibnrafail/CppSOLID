#pragma once

#include "Publisher.hpp"

class ISensor : public Publisher
{
public:
    virtual ~ISensor() = default;

    virtual void operator()() = 0;
};
