#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

void debouncing(int botton_pin, int botton_number, int *counter)
{
    while (!gpio_get(botton_pin))
    {
        printf("Botao %d: %d\n", botton_number, (*counter)++);
        sleep_ms(300);
    };
}

int main()
{
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);

    int cnt_1 = 0;
    int cnt_2 = 0;

    while (true)
    {
        debouncing(BTN_PIN, 1, &cnt_1);
        debouncing(BTN_PIN_2, 2, &cnt_2);
    }
}