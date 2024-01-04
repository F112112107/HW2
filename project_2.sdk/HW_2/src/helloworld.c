#include <stdio.h>
#include <stdlib.h>
#include "xparameters.h"		// �Ѽƶ�.
#include "xgpio.h"	// ²��PS��PL��GPIO�ާ@����Ʈw.

// �����.
void delay(int dly)
{
    int i, j;
    for (i = 0; i < dly; i++) {
    	for (j = 0; j < 0xffff; j++) {
    		;
        }
    }
}

// �D�{��.
int main()
{
    XGpio LED_XGpio;		// �ŧi�@��GPIO�Ϊ����c.
    XGpio SW_XGpio;
    int LED_num = 0b11000011;	// �ŧi�@���ܼ�,���B��μȦs��.

    XGpio_Initialize(&LED_XGpio, XPAR_AXI_GPIO_0_DEVICE_ID);	// ��l��LED_XGpio.
    XGpio_SetDataDirection(&LED_XGpio, 1, 0);		// �]�m�q�D.

    XGpio_Initialize(&SW_XGpio, XPAR_AXI_GPIO_1_DEVICE_ID);	// ��l��LED_XGpio.
    XGpio_GetDataDirection(&SW_XGpio, 1);

    printf("Start!!!");

    int sw;

    while(1) {
    	printf("LED_num = 0x%x\n", LED_num);

    	sw = XGpio_DiscreteRead(&SW_XGpio, 1);
    	XGpio_DiscreteWrite(&LED_XGpio, 1, sw);		// LED_XGpio�q�D,�eLED_num�ȶi�h.

    	//LED_num = ~LED_num;		// LED_num�ܼƤϬ�.

    	//delay(1000);
    }

    return 0;
}
