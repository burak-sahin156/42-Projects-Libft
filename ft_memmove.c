#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 1;
	if (ptr_src < ptr_dst)
	{
		while (i <= len)
		{
			ptr_dst[len - i] = ptr_src[len - i];
			i++;
		}
	}
	else
		ft_memcpy(ptr_dst, ptr_src, len);
	return (dst);
}
