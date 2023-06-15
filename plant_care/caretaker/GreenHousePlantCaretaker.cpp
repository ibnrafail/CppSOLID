#include "GreenHousePlantCaretaker.hpp"

#include <iostream>

void GreenHousePlantCaretaker::update(LightSensorEvent const &event)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    switch (event)
    {
    case LightSensorEvent::MUCH_SUN:
        m_windowDriver.closeWindowBlinds();
        break;
    case LightSensorEvent::LITTLE_SUN:
        m_windowDriver.openWindowBlinds();
        break;
    default:
        std::cerr << "Unknown LightSensorEvent received." << std::endl;
        break;
    }
}

void GreenHousePlantCaretaker::update(HumiditySensorEvent const &event)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    switch (event)
    {
    case HumiditySensorEvent::AIR_DRY:
        m_waterDriver.sprinkleWater();
        break;
    case HumiditySensorEvent::SOIL_DRY:
        m_waterDriver.pourWater();
        break;
    default:
        std::cerr << "Unknown HumiditySensorEvent received." << std::endl;
        break;
    }
}
