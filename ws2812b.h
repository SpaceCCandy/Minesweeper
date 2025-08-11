// SPDX-License-Identifier: MPL-2.0
/*
 * ws2812b.h -- WS2812B driver
 * Copyright (C) 2025  Jacob Koziej <jacobkoziej@gmail.com>
 */
#include <assert.h>
#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>
#include <util/delay.h>

#define ROWS    3
#define COLUMNS 3
#define FACES 5
#define PIXELS  (FACES * ROWS * COLUMNS)

#ifndef WS2812B_H
#define WS2812B_H

#include <stdint.h>

typedef enum ws2812b_color {
    WS2812B_COLOR_GREEN,
    WS2812B_COLOR_RED,
    WS2812B_COLOR_BLUE,
    WS2812B_COLOR_TOTAL,
} ws2812b_color_t;

static union {
    display_buffer_t display;
    ws2812b_buffer_t ws2812b[PIXELS];
} buffer;

static_assert(
    sizeof(buffer.display) == sizeof(buffer.ws2812b),
    "display and ws2812b buffers must match in size");

typedef uint8_t display_buffer_t[FACES][ROWS][COLUMNS][WS2812B_COLOR_TOTAL];

static volatile uint8_t * const PIXELS_DDR  = &DDRD;
static volatile uint8_t * const PIXELS_PORT = &PORTD;
static const uint8_t            PIXELS_BIT  = PD0;

typedef uint8_t ws2812b_buffer_t[WS2812B_COLOR_TOTAL];

void ws2812b_tx(
    volatile uint8_t * const port,
    const uint8_t bit,
    const ws2812b_buffer_t * const buffer,
    const size_t pixels);

#endif  // WS2812B_H