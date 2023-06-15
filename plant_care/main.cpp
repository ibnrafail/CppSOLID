#include "HumiditySensor.hpp"
#include "LightSensor.hpp"
#include "GreenHousePlantCaretaker.hpp"
#include "GardenPlantCaretaker.hpp"

#include <thread>
#include <memory>
#include <vector>

#include "TempPublisher.hpp"
#include "TempObserver.hpp"


#include <iostream>


int main()
{
    auto gardenPlantCaretaker = std::make_unique<GardenPlantCaretaker>();
    auto greenHousePlantCaretaker = std::make_unique<GreenHousePlantCaretaker>();

    auto humiditySensor = std::make_unique<HumiditySensor>();
    auto lightSensor = std::make_unique<LightSensor>();

    humiditySensor->subscribe(*gardenPlantCaretaker);
    humiditySensor->subscribe(*greenHousePlantCaretaker);

    lightSensor->subscribe(*greenHousePlantCaretaker);


    std::thread lightSensorThread(*lightSensor);
    std::thread humiditySensorThread(*humiditySensor);

    lightSensorThread.join();
    humiditySensorThread.join();

    return 0;
}