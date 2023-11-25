#include "STD_Types.h"
#include "BIT_MATH.h"

#define FLASH_BASE_ADDRESS (0x80000000)
uint8 asciiToHex(char asciiChar) {
    if (asciiChar >= '0' && asciiChar <= '9') {
        return asciiChar - '0';
    } else if (asciiChar >= 'A' && asciiChar <= 'F') {
        return asciiChar - 'A' + 10;
    } else if (asciiChar >= 'a' && asciiChar <= 'f') {
        return asciiChar - 'a' + 10;
    } else {

        return -1;
    }
}

 void Hex_Parser_Data( uint8 * Record ){
     uint8  Byte_Count1 , Byte_Count2 ;
     uint8 ADD1 , ADD2 , ADD3 , ADD4 ;
     uint16 Byte_Count ; uint32 Address ;
     Byte_Count1 =asciiToHex (Record[1] ) ;
     Byte_Count2 =asciiToHex (Record[2] ) ;
     ADD1 = asciiToHex (Record[3] ) ;
     ADD2 = asciiToHex (Record[4] ) ;
     ADD3 =asciiToHex (Record[5] ) ;
     ADD4 =asciiToHex (Record[6] ) ;
     Byte_Count= ( Byte_Count1 >> 4 ) | Byte_Count2 ;
     Address=( ADD1 >> 12 ) | ( ADD2 >> 8 ) | ( ADD3 >> 4 ) | ( ADD4); //Increase the base address of flash
     Address+=FLASH_BASE_ADDRESS;
 }