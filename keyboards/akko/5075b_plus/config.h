// Copyright 2026 rijojohn
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* WS2812 chain on SPIM2 MOSI (B15) - matches the stock firmware, which bit-expands
 * each colour byte into 4 SPI bytes and sends 105 * 12 bytes plus a reset tail. */
#define WS2812_SPI_DRIVER SPIDM2
#define WS2812_SPI_MOSI_PAL_MODE 5

/* Written verbatim into SPI BAUDR: SCK = PCLK2 / value = 96MHz / 24 = 4MHz.
 * That reproduces the stock timing (T0H 0.25us, T1H 0.75us). Requires the local
 * ws2812_custom.c, since QMK's stock driver only allows power-of-two divisors. */
#define WS2812_SPI_DIVISOR 24
