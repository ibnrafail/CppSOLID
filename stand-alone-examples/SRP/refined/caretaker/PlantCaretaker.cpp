#include "PlantCaretaker.hpp"

#include <iostream>

template <typename T>
std::pair<bool, T> ConvertAnyToType(boost::any const &data)
{
    bool result = true;
    T outValue = T();

    try
    {
        outValue = boost::any_cast<T>(data);
    }
    catch (boost::bad_any_cast &e)
    {
        result = false;
    }
    return std::make_pair(result, outValue);
}

void PlantCaretaker::update(boost::any const &data)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    auto lightEvent = ConvertAnyToType<LightSensorEvent>(data);
    if (lightEvent.first)
    {
        handleLightEvent(lightEvent.second);
        return;
    }

    auto humidityEvent = ConvertAnyToType<HumiditySensorEvent>(data);
    if (humidityEvent.first)
    {
        handleHumidityEvent(humidityEvent.second);
        return;
    }
}

void PlantCaretaker::handleLightEvent(LightSensorEvent const &event)
{
    switch (event)
    {
    case LightSensorEvent::MUCH_SUN:
        handleMuchSunlight();
        break;
    case LightSensorEvent::LITTLE_SUN:
        handleLittleSunlight();
        break;
    default:
        std::cerr << "Unknown LightSensorEvent received." << std::endl;
        break;
    }
}

void PlantCaretaker::handleMuchSunlight()
{
    m_windowDriver.closeWindowBlinds();
}

void PlantCaretaker::handleLittleSunlight()
{
    m_windowDriver.openWindowBlinds();
}

void PlantCaretaker::handleHumidityEvent(HumiditySensorEvent const event)
{
    switch (event)
    {
    case HumiditySensorEvent::AIR_DRY:
        handleDryAir();
        break;
    case HumiditySensorEvent::SOIL_DRY:
        handleDrySoil();
        break;
    default:
        std::cerr << "Unknown HumiditySensorEvent received." << std::endl;
        break;
    }
}

void PlantCaretaker::handleDryAir()
{
    m_waterDriver.sprinkleWater();
}

void PlantCaretaker::handleDrySoil()
{
    m_waterDriver.pourWater();
}
