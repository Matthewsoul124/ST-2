// Copyright 2024 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

double calculateEarthRopeGap();

struct PoolCalculationResult {
  double concreteCost;
  double fenceCost;
};

PoolCalculationResult calculatePoolCosts();

#endif // INCLUDE_TASKS_H_

