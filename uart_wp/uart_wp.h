#ifndef UART_WP_H
#define UART_WP_H

#include "../utils/com_types.h"

extern com_data_t com;

retType Compare_CRC(u32 host_crc, u32 calc_crc);
u32 Calculate_CRC();
u32 Get_CRC(com_data_t *data);

#endif //UART_WP_H