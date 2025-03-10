#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_RED = 28;

const int LED_RED = 5;
const int LED_ROXO = 8;
const int LED_AZUL = 11;
const int LED_AMARELO = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN_RED);
  gpio_set_dir(BTN_RED, GPIO_IN);
  gpio_pull_up(BTN_RED); // Ativando pull-up

  gpio_init(LED_RED);
  gpio_set_dir(LED_RED, GPIO_OUT);
  gpio_init(LED_ROXO);
  gpio_set_dir(LED_ROXO, GPIO_OUT);
  gpio_init(LED_AZUL);
  gpio_set_dir(LED_AZUL, GPIO_OUT);
  gpio_init(LED_AMARELO);
  gpio_set_dir(LED_AMARELO, GPIO_OUT);
  
  while (true) {
    if (!gpio_get(BTN_RED))
    {
      gpio_put(LED_RED, 1);
      sleep_ms(300);
      gpio_put(LED_RED, 0);

      gpio_put(LED_ROXO, 1);
      sleep_ms(300);
      gpio_put(LED_ROXO, 0);

      gpio_put(LED_AZUL, 1);
      sleep_ms(300);
      gpio_put(LED_AZUL, 0);

      gpio_put(LED_AMARELO, 1);
      sleep_ms(300);
      gpio_put(LED_AMARELO, 0);

      while (!gpio_get(BTN_RED)) {
      };

    }
    // Use delay de 300 ms entre os estados!
  }
}
