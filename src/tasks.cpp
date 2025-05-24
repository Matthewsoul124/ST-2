// Copyright 2024 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

double calculateEarthRopeGap() {
    const double EARTH_RADIUS = 6378.1 * 1000; // в метрах
    const double ADDITIONAL_LENGTH = 1.0; // в метрах

    Circle earth(EARTH_RADIUS);
    double originalFerence = earth.getFerence();
    double newFerence = originalFerence + ADDITIONAL_LENGTH;

    earth.setFerence(newFerence);
    double newRadius = earth.getRadius();

    return newRadius - EARTH_RADIUS;
}

PoolCalculationResult calculatePoolCosts() {
    const double POOL_RADIUS = 3.0; // в метрах
    const double PATH_WIDTH = 1.0; // в метрах
    const double CONCRETE_COST_PER_SQUARE_METER = 1000.0; // в рублях
    const double FENCE_COST_PER_METER = 2000.0; // в рублях

    Circle pool(POOL_RADIUS);
    Circle poolWithPath(POOL_RADIUS + PATH_WIDTH);

    // Расчет стоимости бетонной дорожки
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double concreteCost = pathArea * CONCRETE_COST_PER_SQUARE_METER;

    // Расчет стоимости ограды
    double fenceLength = poolWithPath.getFerence();
    double fenceCost = fenceLength * FENCE_COST_PER_METER;

    return {concreteCost, fenceCost};
} 