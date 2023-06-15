#include "GardenPlantCaretaker.hpp"

#include <iostream>

void GardenPlantCaretaker::update(HumiditySensorEvent const &event)
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