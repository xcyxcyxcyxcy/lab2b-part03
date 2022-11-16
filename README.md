# lab2b-part03

## TODO:

Create a 'sequencer' that allows you to record BOOT button presses and play them on the Neopixel, and also play a sequence of read/write commands. You should be able to:

1. record at a least a few seconds of button input to your RP2040 (in RAM)
2. replay a recorded sequence on your NeoPixel
3. loop a recording
4. save a recording to your laptop (the Python Serial library is one way to do this)
5. play a recording from your laptop
6. record 'macros' (a sequence of console commands) based on keystrokes in your serial console
7. hand-edit a list of register read/write commands on your laptop, and play them on the RP2040
8. include multiple I/O sources in a recording, and remap among the following:
9. inputs: BOOT button, console commands, register read/write commands
10. outputs: neopixel color, neopixel brightness, data over serial, register read/write commands

## In order to reach these functions, we have these codes:
1. the [bootpress.c](https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/code/bootpress.c) for 3 functions: record, replay and loopplay
2. the [data_transfer.c](https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/code/data_transfer.c) for encoding and decoding
3. the [neopixel.c](https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/code/neopixel.c)
4. the [sequencer.c](https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/code/sequencer.c) for realizing the whole functions which are requested.

## Results:
1. record and replay:

a. screen: <div align=center><img width="300" height="200" src="https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/record%20and%20replay.png"/></div>

b. demo: <div align=center><img width="400" height="600" src="https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/record.gif"/></div>

<div align=center><img width="400" height="600" src="https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/replay.gif"/></div>

2. loop:

a. screen: <div align=center><img width="300" height="150" src="https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/loop.png"/></div>

b. demo: <div align=center><img width="400" height="600" src="https://github.com/xcyxcyxcyxcy/lab2b-part03/blob/main/record%20and%20replay.png"/></div>

3. save and upload
