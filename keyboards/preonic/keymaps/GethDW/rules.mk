# MCU name
MCU = STM32F303

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
# FEATURE
BOOTMAGIC_ENABLE = no   # Virtual DIP switch configuration.
MOUSEKEY_ENABLE = no    # Mouse keys.
EXTRAKEY_ENABLE = no    # Audio control and System control.
CONSOLE_ENABLE = no     # Console for debug.
COMMAND_ENABLE = no     # Commands for debug and configuration.
NKRO_ENABLE = yes       # Nkey Rollover if this doesn't work, see here:
						# https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work.
UNICODEMAP_ENABLE = yes

# HARDWARE
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality.
MIDI_ENABLE = no        # MIDI controls.
AUDIO_ENABLE = yes      # Audio output.
BLUETOOTH_ENABLE = no   # Enable Bluetooth with the Adafruit EZ-Key HID.
RGBLIGHT_ENABLE = yes	# Enable WS2812 RGB underlight.
ENCODER_ENABLE = no 	# Support for rotatry encoder.
DIP_SWITCH_ENABLE = no	# Support for DIP switch.
SERIAL_LINK_ENABLE = no

