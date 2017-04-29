#include "tst_round_round.h"
#include "tst_round_ellipse.h"
#include "tst_round_arc.h"
#include "tst_ellipse_ellipse.h"
#include "tst_ellipse_arc.h"
#include "tst_arc_arc.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
