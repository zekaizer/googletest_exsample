#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>

int bcm2835_init();
void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode);

#ifdef __cplusplus
}
#endif