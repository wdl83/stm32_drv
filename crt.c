#include <stddef.h>

extern char *const _text_end;
extern char *const _data_begin;
extern const char *const _data_end;
extern char *const _bss_begin;
extern const char *const _bss_end;

extern void main(void);

__attribute__((naked))
void irqReset(void)
{
    {
        // .data - non-zero initialized data
        char *src = _text_end;
        char *dst = _data_begin;

        while(dst != _data_end) *(dst++) = *(src++);
    }
    {
        // .bss: zero initialized data
        char *begin = _bss_begin;
        while(begin != _bss_end) *(begin) = 0;
    }
    main();
}
