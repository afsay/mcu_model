#!/bin/bash
make clean
make
pyocd flash MKL46Z4_OOP_Model.axf
pyocd-gdbserver

