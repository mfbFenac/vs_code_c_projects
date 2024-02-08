#include <stdio.h>
#include "toplama.h"
#include "stdint.h"

/*
 text    data     bss     dec     hex filename 
14488    1532     112   16132    3f04 code_size_comparison.exe (NOT OPTIMIZED)
14424    1532     112   16068    3ec4 code_size_comparison.exe (OPTIMIZED)
64B      0        0     64B
  */

int main()
{
    uint8_t x = 0;
    uint8_t mcb_tx_buffer[4];
    uint32_t temp_bissframe = 0;

#define USE_OPTIMIZED_CODE          1

#if (USE_OPTIMIZED_CODE == 0) //terminal screen type "size code_size_comparison.exe"

/*
text    data     bss     dec     hex filename
14488    1532     112   16132    3f04 code_size_comparison.exe
*/
    if(x==3)
    {
        mcb_tx_buffer[0] = (uint8_t)(temp_bissframe >> 16);
        mcb_tx_buffer[1] = (uint8_t)(temp_bissframe >> 8);
        mcb_tx_buffer[2] = (uint8_t)temp_bissframe;
    }
    else if(x==4)
    {
        mcb_tx_buffer[0] = (uint8_t)(temp_bissframe >> 24);
        mcb_tx_buffer[1] = (uint8_t)(temp_bissframe >> 16);
        mcb_tx_buffer[2] = (uint8_t)(temp_bissframe >> 8);
        mcb_tx_buffer[3] = (uint8_t)temp_bissframe;
    }
    else if(x==2)
    {
        mcb_tx_buffer[0] = (uint8_t)(temp_bissframe >> 8);
        mcb_tx_buffer[1] = (uint8_t)temp_bissframe;
    }
    else if(x==1)
    {
        mcb_tx_buffer[0] = (uint8_t)temp_bissframe;
    }
#else (USE_OPTIMIZED_CODE == 1)
/*
 text    data     bss     dec     hex filename                                                                                            
14424    1532     112   16068    3ec4 code_size_comparison.exe
  */
    for (int i = 0; i < x; ++i) {
        mcb_tx_buffer[i] = (uint8_t)(temp_bissframe >> (8 * (x - 1 - i)));
    }
#endif

    return 0;
}
