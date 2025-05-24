// Copyright 2024 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

// Функция для решения задачи "Земля и верёвка"
// Возвращает величину зазора в метрах
double calculateEarthRopeGap();

// Функция для решения задачи "Бассейн"
// Возвращает структуру с результатами расчетов
struct PoolCalculationResult {
    double concreteCost;  // Стоимость бетонной дорожки
    double fenceCost;     // Стоимость ограды
};

PoolCalculationResult calculatePoolCosts();

#endif  // INCLUDE_TASKS_H_
