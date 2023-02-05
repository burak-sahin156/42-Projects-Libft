#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void		check_strndup(int n)
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*str_dup;

	if (!(str_dup = ft_strndup(str, n)))
		ft_print_result("NULL");
	else
		ft_print_result(str_dup);
	if (str_dup == str)
		ft_print_result("\nstr_dup's adress == str's adress");
	else
		free(str_dup);
}

int				main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_strndup(11);
	else if (arg == 2)
		check_strndup(0);
	else if (arg == 3)
		check_strndup(30);
	return (0);
}
