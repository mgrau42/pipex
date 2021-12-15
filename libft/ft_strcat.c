
#include "libft.h"

unsigned int	ft_strcat(char *dest, char *src)
{
	unsigned int		i;
	unsigned int		b;

	i = ft_strlen(dest);
	b = ft_strlen(src) + i;
	if (!(dest))
		return (b);
	while ((*src))
		dest[i++] = *src++;
	dest[i] = 0;
	return (b);
}
