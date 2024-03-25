# My personal Configurations Can Be Found Here

## Building for the helios controller
qmk compile -kb lily58/rev1 -km default -e CONVERT_TO=helios
## Dependencies
sudo apt-get install gcc unzip wget zip gcc-avr binutils-avr avr-libc dfu-programmer dfu-util gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi
## UDEV Rules
For flashing, look at https://github.com/qmk/qmk_firmware/blob/master/docs/faq_build.md for udev rules
