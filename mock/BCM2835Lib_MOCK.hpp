#include "gmock/gmock.h"
#include "BCM2835Lib.h"

class BCM2835Lib_MOCK
{
public:
    virtual ~BCM2835Lib_MOCK() {}

    // mock methods
    MOCK_METHOD0(bcm2835_init, int());
    MOCK_METHOD2(bcm2835_gpio_fsel, void(uint8_t, uint8_t));

    // pointer for accessing mocked library
    static std::unique_ptr<BCM2835Lib_MOCK> instancePtr;
};
