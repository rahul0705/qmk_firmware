RGB_MATRIX_EFFECT(double_rainbow)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "rgb_matrix.h"

static bool double_rainbow(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV hsv = { 0, rgb_matrix_config.sat, rgb_matrix_config.val };
    uint8_t key_val = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 4 );
    uint8_t underglow_val = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 2);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_led led = g_rgb_leds[i];
        point_t point = led.point;
        if (led.matrix_co.raw != 0xFF) {
            // Keys, so go up/down
            hsv.h = point.y - key_val;
        } else {
            // Underglow, cycle through colors
            hsv.h = underglow_val;
        }
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
