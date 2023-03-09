#pragma once

#include "ISensor.hpp"
#include <chrono>

enum class HumiditySensorEvent
{
    AIR_DRY,
    SOIL_DRY,
    UNKNOWN
};

class HumiditySensor : public ISensor
{
public:
    virtual ~HumiditySensor() = default;

    void operator()() override;

private:
    bool isAirTooDry() const;

    bool isSoilTooDry() const;

    int getAirMoisture() const;

    int getSoilMoisture() const;

    const int m_min{0};
    const int m_max{10};
    const int m_threshold{3};

    const std::chrono::seconds m_sleepTime{2};
};
