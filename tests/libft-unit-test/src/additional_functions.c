
#include "libft_test.h"


int simple_memcmp (const char *s1, const char *s2, size_t n)
{
	int ret = 0;

	while (n-- && (ret = *(unsigned char *) s1++ - *(unsigned char *) s2++) == 0);
	return ret;
}

/*
 * Compact implementation of utf-8 decoding
*/

int     nbr_bits(unsigned int nbr)
{
    int     i;

    i = 1;
    while ((nbr = nbr >> 1))
        i++;
    return (i);
}

void    putwchart(int wchar, int *len, char *buff)
{
    unsigned int    ch;
    int             n;
    int             i = 0;

    ch = (unsigned int)wchar;
    n = nbr_bits(ch);
    if (n > 7 && ((*len += 1)))
    {
        if (n > 11 && ((*len += 1)))
        {
            if (n > 16 && ((*len += 2)))
            {
                buff[i++] = ((ch >> 18) & 7) | 240;
                buff[i++] = ((ch >> 12) & 63) | 128;
            }
            else if ((*len += 1))
                buff[i++] = ((ch >> 12) & 15) | 224;
            buff[i++] = ((ch >> 6) & 63) | 128;
        }
        else if ((*len += 1))
            buff[i++] = ((ch >> 6) & 31) | 192;
        buff[i++] = (ch & 63) | 128;
    }
    else if ((*len += 1))
        buff[i++] = ch;
}

int     ft_putwstr(wchar_t *wstr, char *buff)
{
    int     len;
    int     ret;
    int     i;

    len = 0;
    ret = 0;
    i = 0;
    if (wstr != NULL)
        while (wstr[i])
        {
            putwchart(wstr[i], &len, buff);
            ret += len;
            i++;
        }
    else
    {
        strcat(buff, "(null)");
        ret = 6;
    }
    return (ret);
}
