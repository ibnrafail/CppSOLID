#include "HumiditySensor.hpp"
#include "LightSensor.hpp"
#include "PlantCaretaker.hpp"

#include <thread>

int main()
{
    PlantCaretaker caretaker1;
    PlantCaretaker caretaker2;

    HumiditySensor humiditySensor;
    LightSensor lightSensor;

    lightSensor.subscribe(caretaker1);
    lightSensor.subscribe(caretaker2);
    humiditySensor.subscribe(caretaker1);
    humiditySensor.subscribe(caretaker2);

    std::thread lightSensorThread(lightSensor);
    std::thread humiditySensorThread(humiditySensor);

    lightSensorThread.join();
    humiditySensorThread.join();

    lightSensor.unsubscribe(caretaker1);
    lightSensor.unsubscribe(caretaker2);
    humiditySensor.unsubscribe(caretaker1);
    humiditySensor.unsubscribe(caretaker2);

    return 0;
}