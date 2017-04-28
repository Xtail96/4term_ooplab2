#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../../../src/arc.h"
#include "../../../src/ellipse.h"
#include "../../../src/round.h"


using namespace testing;

TEST(RoundTestSet, CircleTwoPoints)
{
    Round r1(0, 0, 1);
    Round r2(0, 1, 1);

    int result = r2.intersect(r1);

    EXPECT_EQ(result, 2);
}

TEST(RoundTestSet, CircleOnePoint)
{
    Round r1(1, 1, sqrt(2));
    Round r2(-1, -1, sqrt(2));

    int result = r2.intersect(r1);

    EXPECT_EQ(result, 1);
}

TEST(RoundTestSet, CircleNoPoints)
{
    Round r1(10, 10, 1);
    Round r2(-10, -10, 1);

    int result = r2.intersect(r1);

    EXPECT_EQ(result, 0);
}

TEST(RoundTestSet, EllipseFourPoints)
{
    Ellipse e1(0, 0, 10, 2);
    Ellipse e2(0, 0, 2, 11);

    int result = e1.intersect(e2);

    EXPECT_EQ(result, 4);
}
