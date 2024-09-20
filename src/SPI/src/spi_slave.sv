// Module for SPI Slave
// Based on https://github.com/nandland/spi-slave

`timescale 1ns / 1ps

module spi_slave
    #(
    parameter signed FRAMEWIDTH = 8,
    parameter signed SPI_MODE = 0           // Which SPI mode should it run
    ) (
    input   rstn
    );

endmodule
