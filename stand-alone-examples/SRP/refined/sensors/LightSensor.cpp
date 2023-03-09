#include "LightSensor.hpp"

#include <random>
#include <iostream>
#include <thread>

void LightSensor::operator()()
{
    for (;;)
    {
        const auto sunlight = isSunlight();
        std::cout << "Sun on: " << std::boolalpha << sunlight << std::endl;

        if (isTooMuchSunlight(sunlight))
        {
            m_sensorOn = false;
            notify(LightSensorEvent::MUCH_SUN);
        }
        else if (isTooLittleSunlight(sunlight))
        {
            m_sensorOn = true;
            notify(LightSensorEvent::LITTLE_SUN);
        }

        std::this_thread::sleep_for(m_sleepTime);
    }
}

bool LightSensor::isTooMuchSunlight(const bool sunlight)
{
    if (sunlight)
    {
        auto timeNow = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsedSeconds = timeNow - (*m_sunlightOnFrom);
        return elapsedSeconds.count() > m_threshold;
    }
    return false;
}

bool LightSensor::isTooLittleSunlight(const bool sunlight)
{
    if (not sunlight)
    {
        auto timeNow = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsedSeconds = timeNow - (*m_sunlightOffFrom);
        return elapsedSeconds.count() > m_threshold;
    }
    return false;
}

bool LightSensor::isSunlight()
{
    /**
     * We simulate changes of sunlight by generating random numbers that represent
     * a probability of change in sunlight conditions: if the sun shines or not.
     */
    static bool sunlightOn = true;
    static std::mt19937 generator;

    auto prob = std::uniform_int_distribution<int>(1, 100)(generator);
    if (prob >= 90)
    {
        sunlightOn = !sunlightOn;
    }

    const auto currentTime = std::chrono::system_clock::now();
    if (sunlightOn and m_sensorOn)
    {
        m_sunlightOnFrom = m_sunlightOnFrom ? *m_sunlightOnFrom : currentTime;
        m_sunlightOffFrom = std::nullopt;
    }
    else if (not sunlightOn)
    {
        m_sunlightOffFrom = m_sunlightOffFrom ? *m_sunlightOffFrom : currentTime;
        m_sunlightOnFrom = std::nullopt;
    }

    return sunlightOn;
}