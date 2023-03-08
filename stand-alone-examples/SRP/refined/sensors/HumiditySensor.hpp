#pragma once

#include "ISensor.hpp"

class HumiditySensor : public ISensor
{
public:
    virtual ~HumiditySensor() = default;

    void operator()() override;
};
