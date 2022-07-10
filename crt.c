#include <stdint.h>

/* symbols defined in linker script */
extern uintptr_t _text_end;
extern uintptr_t _data_begin;
extern uintptr_t _data_end;
extern uintptr_t _bss_begin;
extern uintptr_t _bss_end;

extern void main(void);

__attribute__((naked))
void isrReset(void)
{
    {
        // .data - non-zero initialized data
        char *begin = (char *)&_data_begin;
        const char *const end = (const char *)&_data_end;
        const char *src = (const char *)&_text_end;

        while(begin != end) *(begin++) = *(src++);
    }
    {
        // .bss: zero initialized data
        char *begin = (char *)&_bss_begin;
        const char *const end = (const char *)&_bss_end;

        while(begin != end) *(begin++) = 0;
    }

    main();
}
