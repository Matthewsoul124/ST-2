// Copyright 2024 UNN-CS
#include <cmath>
#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, ConstructorTest) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5.0);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 5.0 * 5.0);
}

TEST(CircleTest, SetRadiusTest) {
  Circle c(1.0);
  c.setRadius(2.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 2.0);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 2.0 * 2.0);
}

TEST(CircleTest, SetFerenceTest) {
  Circle c(1.0);
  double newFerence = 10.0;
  c.setFerence(newFerence);
  EXPECT_DOUBLE_EQ(c.getFerence(), newFerence);
  EXPECT_DOUBLE_EQ(c.getRadius(), newFerence / (2 * M_PI));
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * pow(newFerence / (2 * M_PI), 2));
}

TEST(CircleTest, SetAreaTest) {
  Circle c(1.0);
  double newArea = 10.0;
  c.setArea(newArea);
  EXPECT_DOUBLE_EQ(c.getArea(), newArea);
  EXPECT_DOUBLE_EQ(c.getRadius(), sqrt(newArea / M_PI));
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * sqrt(newArea / M_PI));
}

TEST(CircleTest, NegativeRadiusTest) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, NegativeFerenceTest) {
  Circle c(1.0);
  EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, NegativeAreaTest) {
  Circle c(1.0);
  EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
}

TEST(CircleTest, ZeroRadiusTest) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, LargeRadiusTest) {
  Circle c(1000000.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1000000.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 1000000.0);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 1000000.0 * 1000000.0);
}

TEST(CircleTest, PrecisionTest) {
  Circle c(1.0);
  double expectedFerence = 2 * M_PI;
  double expectedArea = M_PI;
  EXPECT_NEAR(c.getFerence(), expectedFerence, 1e-10);
  EXPECT_NEAR(c.getArea(), expectedArea, 1e-10);
}

// Тесты для задачи "Земля и верёвка"
TEST(EarthRopeTest, BasicTest) {
  double gap = calculateEarthRopeGap();
  EXPECT_GT(gap, 0.0);
  EXPECT_LT(gap, 1.0);
}

TEST(EarthRopeTest, PrecisionTest) {
  double gap = calculateEarthRopeGap();
  double expectedGap = 1.0 / (2 * M_PI);
  EXPECT_NEAR(gap, expectedGap, 1e-10);
}

// Тесты для задачи "Бассейн"
TEST(PoolTest, BasicTest) {
  auto result = calculatePoolCosts();
  EXPECT_GT(result.concreteCost, 0.0);
  EXPECT_GT(result.fenceCost, 0.0);
}

TEST(PoolTest, ConcreteCostTest) {
  auto result = calculatePoolCosts();
  double expectedConcreteArea = M_PI * (4.0 * 4.0 - 3.0 * 3.0);
  double expectedConcreteCost = expectedConcreteArea * 1000.0;
  EXPECT_NEAR(result.concreteCost, expectedConcreteCost, 1e-10);
}

TEST(PoolTest, FenceCostTest) {
  auto result = calculatePoolCosts();
  double expectedFenceLength = 2 * M_PI * 4.0;
  double expectedFenceCost = expectedFenceLength * 2000.0;
  EXPECT_NEAR(result.fenceCost, expectedFenceCost, 1e-10);
}

TEST(PoolTest, TotalCostTest) {
  auto result = calculatePoolCosts();
  double totalCost = result.concreteCost + result.fenceCost;
  EXPECT_GT(totalCost, 0.0);
}

TEST(PoolTest, CostProportionsTest) {
  auto result = calculatePoolCosts();
  EXPECT_GT(result.fenceCost, result.concreteCost);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
