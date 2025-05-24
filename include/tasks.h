#ifndef TASKS_H
#define TASKS_H

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

#endif // TASKS_H 