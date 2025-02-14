// SPDX-License-Identifier: AGPL-3.0-or-later
#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/** Initializes discharge component. All other functions must be called after
 * this. */
void ed_init();

/** Returns if ED board is available or not. If false, all other commands will
 * be ignored for safety. */
bool ed_available();

/**
 * Write current ED state to the specified buffer.
 * It won't contain newlines.
 */
void ed_dump_state(char* ptr, size_t size);

/**
 * Returns tmperature (degree Celsius) of the board.
 * Returns 255 if temperature reading was not possible.
 */
uint8_t ed_temp();

/**
 * Set polarity to ON or OFF.
 * Wait until polarity change is complete.
 */
void ed_set_energize(bool on);

/**
 * Set specified pulse current.
 * Wait until current change is complete.
 */
void ed_set_current(uint16_t current_ma);

void ed_unsafe_set_gate(bool on);

bool ed_unsafe_get_detect();

/**
 * Apply single pulse. Wait for certain amount of time (a few msec) until pulse
 * starts.
 *
 * max_wait_us: maximum wait time for pulse to start. 5000 (5ms) is a good
 * value.
 *
 * returns:
 * ignition delay time (time between gate on and pulse start), in microsec.
 * UINT16_MAX if pulse didn't happen.
 */
uint16_t ed_single_pulse(uint16_t pulse_us, uint16_t max_wait_us);

/**
 * Read single byte from the specified register.
 * Returns 0 if read failed.
 */
uint8_t ed_read_register(uint8_t reg_addr);

/**
 * Write single byte to the specified register.
 */
void ed_write_register(uint8_t reg_addr, uint8_t data);

