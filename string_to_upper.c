
#include "libft.h"

char	*string_to_upper(char *string)
{
	int		i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
	{
		string[i] = ft_toupper(string[i]);
		i++;
	}
	return (string);
}