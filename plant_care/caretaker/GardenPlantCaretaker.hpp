#pragma once

#include "WaterDriver.hpp"
#include "WindowDriver.hpp"
#include "TempObserver.hpp"
#include "LightSensor.hpp"
#include "HumiditySensor.hpp"

#include <mutex>

class GardenPlantCaretaker : public TempObserver<HumiditySensorEvent>
{
public:
    virtual ~GardenPlantCaretaker() = default;

    void update(HumiditySensorEvent const &event) override;

private:
    std::mutex   m_mutex;
    WaterDriver  m_waterDriver;
};