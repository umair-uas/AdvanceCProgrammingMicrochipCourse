#include <stdio.h>

#define ADRESH 0xDF
#define ADRESL 0x23

int main() {
    union {
        unsigned int u16ADRead;
        struct {
            unsigned char u8ADReadLow;
            unsigned char u8ADReadHigh;
        } STRUCT_ADReadMembers;
    } UNION_ADRead;

    // For A/D Reading in two separate registers:
    UNION_ADRead.STRUCT_ADReadMembers.u8ADReadHigh = (unsigned char)ADRESH;
    UNION_ADRead.STRUCT_ADReadMembers.u8ADReadLow = (unsigned char)ADRESL;

    // Combine the high and low parts into the u16ADRead member
    UNION_ADRead.u16ADRead = (UNION_ADRead.STRUCT_ADReadMembers.u8ADReadHigh << 8) |
                             UNION_ADRead.STRUCT_ADReadMembers.u8ADReadLow;

    // Now u16ADRead contains the full 16-bit A/D conversion result
    printf("Full 16-bit result: %u\n", UNION_ADRead.u16ADRead);

    return 0;
}
