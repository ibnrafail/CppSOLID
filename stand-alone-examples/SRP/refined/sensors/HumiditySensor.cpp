#include "HumiditySensor.hpp"

#include <random>
#include <iostream>
#include <thread>

void HumiditySensor::operator()()
{
    for (;;)
    {
        if (isAirTooDry())
        {
            notify(HumiditySensorEvent::AIR_DRY);
        }
        if (isSoilTooDry())
        {
            notify(HumiditySensorEvent::SOIL_DRY);
        }

        std::this_thread::sleep_for(m_sleepTime);
    }
}

bool HumiditySensor::isAirTooDry() const
{
    return getAirMoisture() < m_threshold;
}

bool HumiditySensor::isSoilTooDry() const
{
    return getSoilMoisture() < m_threshold;
}

/* We simulate changes of moisture by generating random numbers that
 * represent the degree to which something is moisturized,
 * and then we use the threshold for sensors to trigger.
 */
int HumiditySensor::getAirMoisture() const
{
    static std::mt19937 generator;
    return std::uniform_int_distribution<int>(m_min, m_max)(generator);
}

int HumiditySensor::getSoilMoisture() const
{
    static std::mt19937 generator;
    return std::uniform_int_distribution<int>(m_min, m_max)(generator);
}