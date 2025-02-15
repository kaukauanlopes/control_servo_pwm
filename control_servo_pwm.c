#include "hardware/pwm.h" 
#include "pico/stdlib.h" 
#include <stdio.h>       

// Definições de parâmetros do PWM
#define PWM_FREQ 50
#define TOP 25000
#define SERVO_PIN 22
#define CLOCK_DIVIDER 100.0f

// Variáveis globais
uint slice_num;
uint channel;

uint16_t pulse(uint16_t angulo) {
    return 500 + (angulo * (2400 - 500) / 180);
}

void posicao(uint16_t pulse_us) {
    uint16_t level = (pulse_us * TOP) / 20000;
    pwm_set_chan_level(slice_num, channel, level);
}

void servo_setup() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    channel = pwm_gpio_to_channel(SERVO_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, CLOCK_DIVIDER);
    pwm_config_set_wrap(&config, TOP);
    pwm_init(slice_num, &config, true);
}

void rotation() {
    printf("180°\n");
    posicao(pulse(180));
    sleep_ms(5000);

    printf("90°\n");
    posicao(pulse(90));
    sleep_ms(5000);

    printf("0°\n");
    posicao(pulse(0));
    sleep_ms(5000);

    printf("variando entre 0° e 180°\n");
}

void servo_loop() {
    for (uint16_t angulo = 180; angulo > 0; angulo--) {
        posicao(pulse(angulo));
        sleep_ms(10);
    }

    for (uint16_t angulo = 0; angulo <= 180; angulo++) {
        posicao(pulse(angulo));
        sleep_ms(10);
    }}

int main() {
  stdio_init_all();
  servo_setup(); 
  rotation();   

  while (true) {servo_loop();} 
  return 0; 
}
