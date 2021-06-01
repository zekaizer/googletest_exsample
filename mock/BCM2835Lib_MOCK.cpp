#include "BCM2835Lib_MOCK.hpp"

// instantiate mocked lib
std::unique_ptr<BCM2835Lib_MOCK> BCM2835Lib_MOCK::instancePtr;

int bcm2835_init() { return BCM2835Lib_MOCK::instancePtr->bcm2835_init(); }
void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode) { BCM2835Lib_MOCK::instancePtr->bcm2835_gpio_fsel(pin, mode); }
