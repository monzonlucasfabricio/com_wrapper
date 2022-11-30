#include "stdio.h"
#include "uart_wp/uart_wp.h"
#include "crc/crc.h"

com_data_t data_com;
com_func_t functions;

int main(void)
{
    retType ret = SUCCESS;
    com_data_t *data = &data_com;
    u32 zeros = 0;
    memcpy(data->buf,&zeros,sizeof(u32)*256);
    data->crc = 52136;
    data->dir = WRITE;
    data->h_type = HEADER_COMMAND;
    data->size = 10;

    printf("%i %i %i %i\n",data->crc,data->dir,data->h_type,data->size);

    u32 crc = Calculate_CRC();
    printf("Calculate CRC : %i\n",crc);

    ret = Compare_CRC(2,3);
    if (ret != SUCCESS){
        printf("RETURN VALUE : %i\n", ret);
    }
    printf("So Success\n");
    u16 value = 1000;
    functions.argsize = 1;
    functions.arg.a = (void*)value;
    printf("a = %i\n",(u16*)(functions.arg.a));
    functions.arg.b = 0xFF;
    printf("b = %i\n",functions.arg);
    functions.arg.c = 0xFFFF;
    printf("c = %i\n",functions.arg);
    functions.arg.d = 0xFFFFFFFF;
    printf("d = %u\n",functions.arg);
    functions.arg.e = "HOLA MUNDO";
    printf("e = %s\n",functions.arg);
    printf("%s %i\n",functions.arg,sizeof(functions.arg));
    return 0;
}