#include "uart_wp.h"
#include "../crc/crc.h"

/* CRC Not really implemented yet */
unsigned char seed_word[] = "1579006851";

u32 Get_CRC(com_data_t *data){
    return data->crc;
}

u32 Calculate_CRC(){
    u32 res = crcSlow(seed_word,10);
    return res;
}

retType Compare_CRC(u32 host_crc, u32 calc_crc)
{
    if (host_crc != calc_crc)
    {
        return ERROR_CRC;
    }
    return SUCCESS;
}