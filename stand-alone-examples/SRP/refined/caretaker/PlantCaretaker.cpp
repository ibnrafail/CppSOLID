#include "PlantCaretaker.hpp"

void PlantCaretaker::onMuchSunlight()
{
    m_windowDriver.closeWindowBlinds();
}

void PlantCaretaker::onLittleSunlight()
{
    m_windowDriver.openWindowBlinds();
}

void PlantCaretaker::onDryAir()
{
    m_waterDriver.sprinkleWater();
}

void PlantCaretaker::onDrySoil()
{
    m_waterDriver.pourWater();
}

