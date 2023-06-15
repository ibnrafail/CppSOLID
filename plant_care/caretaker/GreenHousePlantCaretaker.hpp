#pragma once

#include "WaterDriver.hpp"
#include "WindowDriver.hpp"
#include "TempObserver.hpp"
#include "LightSensor.hpp"
#include "HumiditySensor.hpp"

#include <mutex>

class GreenHousePlantCaretaker : public TempObserver<LightSensorEvent>, public TempObserver<HumiditySensorEvent>
{
public:
    virtual ~GreenHousePlantCaretaker() = default;

    void update(LightSensorEvent const &event) override;

    void update(HumiditySensorEvent const &event) override;

private:
    std::mutex   m_mutex;
    WaterDriver  m_waterDriver;
    WindowDriver m_windowDriver;
};