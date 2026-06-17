#ifndef HERMES_H
#define HERMES_H

#include <stdint.h>

void HMS_Extract_port(int argc, char** argv, uint16_t* port);

void HMS_Init_server(int* serverSocket, uint16_t* port);

#endif // !HERMES_H
