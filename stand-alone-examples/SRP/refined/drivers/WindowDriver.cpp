#include "WindowDriver.hpp"

#include <iostream>

void WindowDriver::openWindowBlinds()
{
    if (not m_windowBlindsOpen)
    {
        m_windowBlindsOpen = true;
        std::cout << "Opened window blinds" << std::endl;
    }
}

void WindowDriver::closeWindowBlinds()
{
    if (m_windowBlindsOpen)
    {
        m_windowBlindsOpen = false;
        std::cout << "Closed window blinds" << std::endl;
    }
}

bool WindowDriver::areWindowBlindsOpen()
{
    return m_windowBlindsOpen;
}