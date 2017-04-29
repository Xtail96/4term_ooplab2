#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../../src/round.h"

using namespace testing;

TEST(Round_Round_TestSet, CircleTwoPoints)
{
    Round r1(0, 0, 1);
    Round r2(0, 1, 1);

    int result = r2.intersect(r1);

    EXPECT_EQ(result, 2);
}

TEST(Round_Round_TestSet, CircleOnePoint)
{
    Round r1(1, 1, sqrt(2));
    Round r2(-1, -1, sqrt(2));

    int result = r2.intersect(r1);

    EXPECT_EQ(result, 1);
}

TEST(Round_Round_TestSet, CircleCloseEdges)
{
    Round r1(0, 1, 1);
    Round r2(0, -0.99, 1);

    int result = r2.intersect(r1);

    EXPECT_EQ(result, 2);
}

TEST(Round_Round_TestSet, CircleCloseCenters)
{
    Round r1(0, 1, 1);
    Round r2(0, 0.99, 1);

    int result = r2.intersect(r1);

    EXPECT_EQ(result, 2);
}

TEST(Round_Round_TestSet, SameCircle)
{
    Round r(0, 1, 1);

    int result = r.intersect(r);

    EXPECT_EQ(result, -1);
}

TEST(Round_Round_TestSet, CircleNoPoints)
{
    Round r1(10, 10, 1);
    Round r2(-10, -10, 1);

    int result = r2.intersect(r1);

    EXPECT_EQ(result, 0);
}
