#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*s;
	char	*d;
	int		i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	while (n > 0 && s[i] != (char)c)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	if (s[i] == (char)c && n > 0)
		return (&s[i + 1]);
	return (NULL);
}