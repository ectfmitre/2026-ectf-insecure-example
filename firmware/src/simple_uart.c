/**
 * @file "simple_uart.c"
 * @author Samuel Meyers
 * @brief UART Interrupt Handler Implementation
 * @date 2026
 *
 * This source file is part of an example system for MITRE's 2026 Embedded CTF (eCTF).
 * This code is being provided only for educational purposes for the 2026 MITRE eCTF competition,
 * and may not meet MITRE standards for quality. Use this code at your own risk!
 *
 * @copyright Copyright (c) 2026 The MITRE Corporation
 */

#include "simple_uart.h"

/**********************************************************
 *************** HARDWARE ABSTRACTIONS ********************
 **********************************************************/

// This holds the two UART configurations necessary for communication
UART_Regs *uart_inst[] = {UART_0_INST, UART_1_INST};

UART_Regs *get_uart_handle(int uart_id) {
    if (uart_id < 0 || uart_id >= CONFIG_UART_COUNT) {
        // Default on bad input is 0
        return uart_inst[0];
    }
    else {
        return uart_inst[uart_id];
    }
}

/** @brief Reads the next available character from UART.
 *
 *  @param uart_id The index of UART to use
 *  @return The character read.
*/
int uart_readbyte(int uart_id){
    uint8_t data = DL_UART_receiveDataBlocking(get_uart_handle(uart_id));
    return data;
}

/** @brief Writes a byte to UART.
 *
 *  @param uart_id The index of UART to use
 *  @param data The byte to be written.
*/
void uart_writebyte(int uart_id, uint8_t data) {
    DL_UART_transmitDataBlocking(get_uart_handle(uart_id), data);
}

