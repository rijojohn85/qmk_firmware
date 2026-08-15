# Akko 5075B Plus

A 75% board with a knob (SKU `AK5075B/AKCP/CHBLAK`). USB `0x342D:0xE4D7`, WB32FQ95, `wb32-dfu`.

> **This is not `akko/5075`.** The mainline `akko/5075` is a different PCB: 16 matrix columns
> against this board's 15, and an entirely different pinout. Flashing it here produces a
> continuous stream of garbage keystrokes on any host, and recovering needs the pad short below.

Wired USB only - the wireless/Bluetooth side of the Plus is not supported. Keep the bottom
switch on **USB** (middle).

Make example for this keyboard (after setting up your build environment):

    make akko/5075b_plus:rijo:flash

## Hardware

Everything here was recovered from the stock firmware or probed on the device, since no vendor
source is published.

| | |
|---|---|
| Matrix rows | `A0 A1 A2 A3 A4 C13` |
| Matrix cols | `C0 C1 C2 C3 A6 B10 B11 B12 B13 B14 A10 C6 C7 C8 C9` |
| Diode direction | `ROW2COL` |
| Encoder | `pin_a B7`, `pin_b B6` (knob press is matrix `[0,14]`) |
| Lighting | WS2812 chain, 105 LEDs, data on `B15` via SPIM2 |
| LED power | `A8` **and** `A9`, both driven high in `keyboard_pre_init_kb` |

Notes on the lighting, since it is unusual:

- The LEDs are plain WS2812s, not an I2C matrix driver - the firmware references no I2C
  peripheral at all, which is why there is no per-LED register table to be found.
- `WS2812_SPI_DIVISOR` is written straight into SPI `BAUDR` on WB32, so `SCK = PCLK2 / value`.
  PCLK2 is 96MHz and 24 gives 4MHz, the timing the stock firmware uses. QMK's stock SPI driver
  only accepts power-of-two divisors, so `ws2812_custom.c` is a local copy with that restriction
  removed.
- Both power pins matter. With neither, nothing lights. With only `A9`, the first pixel lights and
  the rest of the chain stays unpowered, so it looks like a data fault when it is really a rail.

## Entering the bootloader

Any of:

- `Fn` + `Del` (`QK_BOOT` in the `rijo` keymap)
- hold `Esc` while plugging in (bootmagic)
- `Fn` + `Right Shift` + `Esc` on the stock Akko firmware

If none of those work - which is what happens after flashing firmware for the wrong board - open
the case and short the two pads of `R23` (next to switch position `DW43`, beside the MCU) with
tweezers *while* plugging the cable in. Then flash with:

    wb32-dfu-updater_cli -D <firmware>.bin && wb32-dfu-updater_cli -R

## Keymaps

- `rijo` - home row mods on both Windows and Mac layers, Caps Lock as Ctrl/Esc, VIA, RGB.
- `pinprobe` - diagnostic only. Sets every unused GPIO to input-pullup and logs transitions over
  `qmk console`; this is how the encoder pins were identified. Not a usable keymap.
