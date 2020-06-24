WPM_ENABLE = yes         # Allow WPM count for bongo_cat animation
OLED_DRIVER_ENABLE = yes # Enables the use of OLED displays
ENCODER_ENABLE = yes     # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes    # Enable keyboard RGB underglow
EXTRAFLAGS += -flto      # Enable link time optimization

SRC += encoders.c
SRC += oled.c
