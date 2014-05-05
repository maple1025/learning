/*************************************************
 *  Code to demostrate data structure alignment  *
 *************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct short_array
    {
        short a;
        short b;
        short c;
    };

    struct char_array
    {
        char a;
        char b;
        char c;
    };

    struct message                      // 24
    {
        short opcode;                   // 2
        char subfield;                  // 1
        long message_length;            // 8
        char version;                   // 1
        short destination_processor;    // 2
    };

    struct final_pad                    // 8
    {
        float x;                        // 4
        char n[1];                      // 1
    };

    struct final_pad_short              // 6
    {
        short s;                        // 2
        char n[3];                      // 3
    };

#pragma pack(push)      // push current alignment to stack
#pragma pack(1)         // set alignment to 1 byte boundary

    struct packed_data                  // 10
    {
        char d1;                        // 1
        long d2;                        // 8
        char d3;                        // 1
    };

#pragma pack(pop)

    // allocate memory aligned to cache lines
    double *var;
    int     ok;
    ok = posix_memalign((void**)&var, 64, 10*sizeof(double));
    if (ok != 0)
        printf("posix_memalign error\n");
    printf("var = %p\n", var);

    printf("sizeof(short_array) = %zu\n", sizeof(struct short_array));
    printf("sizeof(char_array) = %zu\n", sizeof(struct char_array));
    printf("sizeof(message) = %zu\n", sizeof(struct message));
    printf("sizeof(final_pad) = %zu\n", sizeof(struct final_pad));
    printf("sizeof(final_pad_short) = %zu\n", sizeof(struct final_pad_short));
    printf("sizeof(packed_data) = %zu\n", sizeof(struct packed_data));

    struct message *m = malloc(sizeof(struct message));

    printf("&m.opcode                   = %p\n", &m->opcode);
    printf("&m.subfield                 = %p\n", &m->subfield);
    printf("&m.message_length           = %p\n", &m->message_length);
    printf("&m.version                  = %p\n", &m->version);
    printf("&m.destination_processor    = %p\n", &m->destination_processor);

    struct short_array sl[10];
    printf("sizeof(sl) = %zu\n", sizeof(sl));

    int *p;
    int i;
    for (i = 0; i < 10; ++i)
    {
        p = malloc(11 * sizeof(int));
        // the address should be multipler of 4
        printf("p = %p, p mod 4 = %d\n", p, (long)p % 4);
    }
    return 0;
}
