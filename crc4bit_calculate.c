#include <stdio.h>
#include "stdint.h"

#define SET_BIT(data, bit, val) (data) &= ~(1<<(bit)); (data) |= (((val) & 0x1) << (bit))
#define GET_BIT(data, bit) (((data)>>(bit))&0x1)
uint32_t R_CRC(uint32_t data, const uint8_t polynomial, const uint8_t seed, const uint8_t dataWidth, const uint8_t crcWidth)
{
  const uint8_t crcTbl[2] = {0x0, polynomial};
  uint8_t lfsr = seed;
  for(int16_t i = dataWidth-1; i >= 0; i--)
  {
    lfsr <<= 1;
    SET_BIT(lfsr, 0, GET_BIT(data, i));
    lfsr ^= crcTbl[GET_BIT(lfsr, crcWidth)];
  }
  return lfsr & ((1 << crcWidth) - 1);
}

// Function to calculate 5-bit CRC
uint8_t calculate_crc_5_bit(uint8_t *data, uint8_t length)
{
    // Define the CRC polynomial for a 5-bit CRC
    uint8_t crc_polynomial = 0x19; // Binary: 11001

    // Initialize the CRC register to 0
    uint8_t crc_register = 0;

    // Perform CRC calculation
    for (uint8_t q = 0; q < length; q++) {
        crc_register ^= (data[q] << 4); // XOR the byte into the upper 4 bits of the CRC register

        for (uint8_t x = 0; x < 8; x++) {
            if (crc_register & 0x10) { // Check if the leftmost bit is 1
                crc_register = (crc_register << 1) ^ crc_polynomial;
            } else {
                crc_register <<= 1;
            }
        }
    }

    // Only keep the lower 4 bits of the CRC register
    crc_register &= 0x0F;

    return crc_register;
}

uint8_t reverse(uint8_t b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}

void crc_hesaplamaca()
{
    uint8_t sonuc=123;
    char baba[2] = {0x20,0x06};
    sonuc = calculate_crc_5_bit(baba,2);
    printf("hesaplanan crc degeri: %d",sonuc);
}

int main() 
{
    // uint32_t sonuc = 0;
    // sonuc = R_CRC(0x0206, 0x5, 0x11, 24, 5);
    // printf("sonuc: %d",sonuc);

    int test_buffer_tx;
    test_buffer_tx = reverse(0x88);
    printf("reverse hex: %x\tdec: %d\n",test_buffer_tx,test_buffer_tx);
    test_buffer_tx = reverse(0x18);
    printf("reverse hex: %x\tdec: %d\n",test_buffer_tx,test_buffer_tx);

    test_buffer_tx = reverse(169);
    printf("reverse hex: %x\tdec: %d\n",test_buffer_tx,test_buffer_tx);

    test_buffer_tx = reverse(0xeb);
    printf("reverse hex: %x\tdec: %d\n",test_buffer_tx,test_buffer_tx);

    crc_hesaplamaca();

    return 0;
}
