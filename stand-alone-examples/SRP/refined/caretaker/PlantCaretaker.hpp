#pragma once

#include "WaterDriver.hpp"
#include "WindowDriver.hpp"
#include "IObserver.hpp"
#include "LightSensor.hpp"
#include "HumiditySensor.hpp"

#include <mutex>

class PlantCaretaker : public IObserver
{
public:
    virtual ~PlantCaretaker() = default;

    void update(boost::any const &data) override;

private:
    void handleLightEvent(LightSensorEvent const &event);

    void handleMuchSunlight();

    void handleLittleSunlight();

    void handleHumidityEvent(HumiditySensorEvent const event);

    void handleDryAir();

    void handleDrySoil();

private:
    std::string  m_name;
    std::mutex   m_mutex;
    WaterDriver  m_waterDriver;
    WindowDriver m_windowDriver;
};