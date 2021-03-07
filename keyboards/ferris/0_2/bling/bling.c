#include "quantum.h"
#include "drivers/issi/is31fl3731.h"

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    /* Refer to IS31 manual for these locations
     *   driver
     *   |  R location
     *   |  |      G location
     *   |  |      |      B location
     *   |  |      |      | */
    {0, C9_15, C8_15, C6_14},  // Left  RGB 0
    {0, C9_14, C8_14, C7_14},  // Left  RGB 1
    {0, C9_13, C8_13, C7_13},  // Left  RGB 2
    {0, C9_12, C8_12, C7_12},  // Left  RGB 3
    {0, C9_11, C8_11, C7_11},  // Left  RGB 4
    {0, C9_10, C8_10, C7_10},  // Left  RGB 5
    {0, C9_9, C8_9, C7_9},     // Left  RGB 6
    {1, C1_2, C2_2, C4_3},     // Right RGB 0
    {1, C1_3, C2_3, C3_3}      // Right RGB 1
    {1, C1_4, C2_4, C3_4},     // Right RGB 2
    {1, C1_5, C2_5, C3_5},     // Right RGB 3
    {1, C1_6, C2_6, C3_6},     // Right RGB 4
    {1, C1_7, C2_7, C3_7},     // Right RGB 5
    {1, C1_8, C2_8, C3_8},     // Right RGB 6
};

#define P(x, y) \
    { (x * 224 / (MATRIX_COLS - 1)), (y * 64 / (MATRIX_ROWS - 1)) }
// clang-format off
led_config_t g_led_config = {
    // Key Matrix to LED Index
    {
        {0,  1,  2},
        {3,  4},
        {5,  6},
        {7, 8,  9},
        {10,  11},
        {12, 13},
    }, {
        // LED Index to Physical Position
        // |      Left      ||    Right      |
        // |   | 3 |   | 0  || 0 |   | 3 |   |
        // | 5 |   |   |    ||   |   |   | 5 |
        // |   |   |   |    ||   |   |   |   |
        // |   |   |   |  1 || 1 |   |   |   |
        // |   | 4 |   |    ||   |   | 4 |   |
        // | 6 |   |   |    ||   |   |   | 6 |
        P(0, 3), P(3, 3), P(5, 3),
        P(0, 1), P(4, 1),
        P(1, 0), P(5, 0),
        P(0, 4), P(3, 4), P(5, 4),
        P(0, 6), P(4, 6),
        P(1, 7), P(5, 7),
    }, {
        // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
    }
};
#undef P
