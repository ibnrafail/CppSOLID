#pragma once

#include "WaterDriver.hpp"
#include "WindowDriver.hpp"

class PlantCaretaker
{
public:
    void onMuchSunlight();

    void onLittleSunlight();

    void onDryAir();

    void onDrySoil();

private:
    WaterDriver m_waterDriver;
    WindowDriver m_windowDriver;
};