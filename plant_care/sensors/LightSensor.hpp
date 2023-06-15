#pragma once

#include "TempPublisher.hpp"

#include <chrono>
#include <optional>

enum class LightSensorEvent
{
    MUCH_SUN,
    LITTLE_SUN,
    UNKNOWN
};

class LightSensor : public TempPublisher<LightSensorEvent>
{
public:
    virtual ~LightSensor() = default;

    void operator()();

private:
    bool isTooMuchSunlight(const bool sunlight);

    bool isTooLittleSunlight(const bool sunlight);

    bool isSunlight();

    using TimePoint = decltype(std::chrono::system_clock::now());

    std::optional<TimePoint> m_sunlightOnFrom;
    std::optional<TimePoint> m_sunlightOffFrom;

    const std::chrono::seconds m_sleepTime{2};

    const int m_threshold = 3;
    bool m_sensorOn = true;
};
