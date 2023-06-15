#include "HumiditySensor.hpp"
#include "LightSensor.hpp"
#include "PlantCaretaker.hpp"

#include <thread>
#include <memory>
#include <vector>

int main()
{
    constexpr uint32_t numberOfCaretakers = 10;

    std::vector<std::unique_ptr<IObserver>> caretakers;
    
    std::vector<std::shared_ptr<ISensor>> sensors;
    std::vector<std::thread> sensorThreads;

    sensors.emplace_back(std::make_shared<HumiditySensor>());
    sensors.emplace_back(std::make_shared<LightSensor>());

    for (uint32_t caretakerIdx = 0; caretakerIdx < numberOfCaretakers; ++caretakerIdx)
    {
        auto &caretaker = caretakers.emplace_back(std::make_unique<PlantCaretaker>());

        for (auto &sensor : sensors)
        {
            sensor->subscribe(*caretaker);
        }
    }

    for (auto &sensor : sensors)
    {
        sensorThreads.emplace_back(std::thread([sensor]() { (*sensor)(); }));
    }

    for (auto &thread : sensorThreads)
    {
        thread.join();
    }

    for (auto &sensor : sensors)
    {
        sensor->unsubscribeAll();
    }

    return 0;
}