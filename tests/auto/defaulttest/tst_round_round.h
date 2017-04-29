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
    Round r2(0, -0.999, 1);

    int result = r2.intersect(r1);

    EXPECT_EQ(result, 2);
}

TEST(Round_Round_TestSet, CircleCloseCenters)
{
    Round r1(1, 0, 1);
    Round r2(0.999, 0, 1);

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

TEST(Round_Round_TestSet, CircleZeroRadius)
{
    Round r(0, 0, 1);
    Round z(0, 1, 0);

    int res1 = r.intersect(z);
    int res2 = z.intersect(r);

    EXPECT_EQ(res1, res2);
    EXPECT_EQ(res1, 1);
}
