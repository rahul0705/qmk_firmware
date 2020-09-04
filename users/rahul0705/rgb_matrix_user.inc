RGB_MATRIX_EFFECT(up_down)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#    include "rgb_matrix.h"

extern led_config_t g_led_config;

static bool up_down(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV     hsv           = rgb_matrix_config.hsv;
    uint8_t key_val       = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 4);
    uint8_t underglow_val = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 4);
    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_ANY_FLAGS(g_led_config.flags[i], (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER))) {
            // Keys, so go up/down
            hsv.h = key_val - g_led_config.point[i].y;
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            // Underglow, cycle through colors
            hsv.h = underglow_val;
        } else {
            hsv.h = 0;
        }
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}
#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
