#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	d;

	c = ft_strlen(dst);
	if (dstsize <= c)
		return (dstsize + ft_strlen(src));
	d = 0;
	while (src[d] && (c + d) < dstsize - 1)
	{
		dst[c + d] = src[d];
		d++;
	}
	dst[c + d] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}
