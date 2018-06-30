ESP32 SD Card reader with SX1509
================================

## The Reason

Sometimes we used almost every GPIO pins on ESP32 for certain purposes. In some cases, ESP32's GPIOs are just not enough. We need more.

One of the problem that we encountered is, how do we do I/O with SD Card but the SS pin is controlled by a GPIO expander like SX1509? Using the `arduino-esp32` built-in library for SD Card is just not possible since the library assumes that the SS pin is connected directly to one of ESP32's GPIOs.

## The Answer

We need to customize the SD card library. Even only just adding `sx.` to every `digitalWrite` and `pinMode` in the code. If you wonder how we do that, then continue reading this document then go look at the code. It's pretty straightforward.

Things to note is we _forked_ the SD card library and change the class name, function name to `SDX` or `sdx_` or `sdcardx_` for function prefix so we don't mess up with the original library.

## The Cost

Maintenance cost. Since we _forked_ the library, we need to maintain the forked library ourselves. 


## How to Run the Project

Make sure you have the SD Card slot on your hardware and the SS pin is connected to one of the pin on SX1509.

To run the code, clone or download this repository and run:

```
pio run -t upload
```

To see the serial output, run:

```
pio device monitor -b 115200 -p [YOUR_SERIAL_PORT]
```

