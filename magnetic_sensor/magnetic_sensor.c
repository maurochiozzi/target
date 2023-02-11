#include "magnetic_sensor.h"

#include "../indexer/indexer.h"
#include "../space/space.h"

void initMagneticSensor(MagneticSensor sensor, int i2c) {
    // init sensor buffer
    sensor.samples = (float*)malloc(sizeof(float) * 2 * sensor.sample_size);
    sensor.indexer.sample_size = sensor.sample_size;

    // init sensor connection
}

int addSample(MagneticSensor sensor, Vector vector) {
    sensor.samples[sensor.indexer.sample] = norm(vector);

    return incrementIndex(sensor.indexer);
}

/**
 * This function will reset the cache of the previous filled cache.
 */
void resetSampleCache(MagneticSensor sensor) {
    const int previous_cache_index = (sensor.indexer.buffer + 1) % 2;

    for (int index = sensor.indexer.buffer * sensor.sample_size;
         index < (sensor.indexer.buffer + 1) * sensor.sample_size; index++) {
        sensor.samples[index] = 0.0;
    }
}
