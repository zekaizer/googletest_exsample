// MOCKING C-Functions with GMOCK :)
#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "BCM2835Lib_MOCK.hpp"
#include "cmodule.h"

using namespace ::testing;
using ::testing::Return;

class TestFixture : public ::testing::Test
{
public:
    TestFixture()
    {
        BCM2835Lib_MOCK::instancePtr.reset(new BCM2835Lib_MOCK());
    }
    ~TestFixture()
    {
        BCM2835Lib_MOCK::instancePtr.reset();
    }
    virtual void SetUp() {}
    virtual void TearDown() {}
};

class BCM2835LibUnitTest : public TestFixture{
public:
    BCM2835LibUnitTest(){
        // here you can put some initializations
    }
};

TEST_F(BCM2835LibUnitTest, inits)
{
    EXPECT_CALL(*BCM2835Lib_MOCK::instancePtr, bcm2835_init()).Times(1).WillOnce(Return(1));

    EXPECT_EQ(1, inits()) << "init must return 1";
}

TEST_F(BCM2835LibUnitTest, pinModeTest)
{

    EXPECT_CALL(*BCM2835Lib_MOCK::instancePtr, bcm2835_gpio_fsel((uint8_t)1, (uint8_t)2))
        .Times(1);

    pinMode((uint8_t)1, (uint8_t)2);
}
