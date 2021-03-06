
#include <string.h>
#include <cutils/log.h>
#include <cutils/properties.h>

#include "sensor_accelerometer.hpp"

AccelerometerSensor::AccelerometerSensor(void)
{
    memset(&sensorCore, 0, sizeof(sensorCore));
    sensorCore.name = "Genymotion Accelerometer";
    sensorCore.vendor = "Genymobile";
    sensorCore.version = 1;
    sensorCore.handle = SENSORS_HANDLE_BASE + SENSOR_TYPE_ACCELEROMETER;
    sensorCore.type = SENSOR_TYPE_ACCELEROMETER;
    sensorCore.maxRange = MAX_RANGE_A;
    sensorCore.resolution = CONVERT_A;
    sensorCore.power = 0.57f;
    sensorCore.minDelay = 5000; // ms

    baseEvent.version = sizeof(sensors_event_t);
    baseEvent.sensor = SENSORS_HANDLE_BASE + SENSOR_TYPE_ACCELEROMETER;
    baseEvent.type = SENSOR_TYPE_ACCELEROMETER;
    baseEvent.timestamp = getTimestamp();
    baseEvent.acceleration.x = 0.;
    baseEvent.acceleration.y = 9.776219;
    baseEvent.acceleration.z = 0.813417;

    memcpy(&lastEvent, &baseEvent, sizeof(lastEvent));

    lastPropertiesWriteTimestamp = 0;
}

AccelerometerSensor::~AccelerometerSensor(void)
{

}

void AccelerometerSensor::generateEvent(sensors_event_t *data, t_sensor_data rawData)
{
    memset(data, 0, sizeof(*data));

    data->version = sizeof(sensors_event_t);
    data->sensor = SENSORS_HANDLE_BASE + SENSOR_TYPE_ACCELEROMETER;
    data->type = SENSOR_TYPE_ACCELEROMETER;
    data->timestamp = getTimestamp();
    data->acceleration.x = rawData.x;
    data->acceleration.y = rawData.y;
    data->acceleration.z = rawData.z;


    // We don't need to write properties every 20 ms, so skip
    if ((data->timestamp - lastPropertiesWriteTimestamp) > ACCELERO_WRITE_MIN_PERIOD) {
        char property[PROPERTY_VALUE_MAX];
        // Save X acceleration
        sprintf(property, "%lf", rawData.x);
        property_set(ACCELEROMETER_X, property);
        // Save Y acceleration
        sprintf(property, "%lf", rawData.y);
        property_set(ACCELEROMETER_Y, property);
        // Save Z acceleration
        sprintf(property, "%lf", rawData.z);
        property_set(ACCELEROMETER_Z, property);
        // save last write timestamp
        lastPropertiesWriteTimestamp = data->timestamp;
    }

    memcpy(&lastEvent, data, sizeof(lastEvent));
}
