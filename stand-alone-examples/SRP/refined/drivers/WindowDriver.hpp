#pragma once

class WindowDriver
{
public:
    WindowDriver() = default;

    void openWindowBlinds();

    void closeWindowBlinds();

    bool areWindowBlindsOpen();

private:
    bool m_windowBlindsOpen{false};
};
