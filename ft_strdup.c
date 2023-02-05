#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dst == NULL)
		return (0);
	if (dst)
		dst = ft_memcpy(dst, s1, ft_strlen(s1));
	dst[ft_strlen(s1)] = '\0';
	return (dst);
}
