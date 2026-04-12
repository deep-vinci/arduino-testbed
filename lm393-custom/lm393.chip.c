#include "wokwi-api.h"
#include <stdlib.h>

typedef struct {
  pin_t pin_vcc;
  pin_t pin_in;
  pin_t pin_out;
  timer_t timer;
} chip_state_t;

void timer_callback(void *user_data) {
  chip_state_t *chip = (chip_state_t *)user_data;

  float vcc = pin_adc_read(chip->pin_vcc);
  float vin = pin_adc_read(chip->pin_in);

  float threshold = vcc / 2.0;

  if (vin > threshold) {
    pin_write(chip->pin_out, HIGH);
  } else {
    pin_write(chip->pin_out, LOW);
  }
}

void chip_init() {
  chip_state_t *chip = malloc(sizeof(chip_state_t));

  chip->pin_vcc = pin_init("VCC", ANALOG);
  chip->pin_in  = pin_init("IN", ANALOG);
  chip->pin_out = pin_init("OUT", OUTPUT);

  timer_config_t timer_config = {
    .callback = timer_callback,
    .user_data = chip
  };

  chip->timer = timer_init(&timer_config);
  timer_start(chip->timer, 100, true);  
}