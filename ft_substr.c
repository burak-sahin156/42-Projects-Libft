#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*strs;
	size_t	strlen;

	if (s == NULL)
		return (NULL);
	strlen = ft_strlen((char *)s);
	if (start > strlen)
		return (ft_strdup(""));
	if (strlen - start >= len)
		strs = (char *)malloc((len + 1) * sizeof(char));
	else
		strs = (char *)malloc((strlen - start + 1) * sizeof(char));
	if (strs == NULL)
		return (NULL);
	ft_strlcpy(strs, (s + start), (len + 1));
	return (strs);
}
//  int main()
//  {
//      char burak[] = "burak deneme kopyala";
//      printf("%s", ft_substr(burak, 6,11));
//  }
