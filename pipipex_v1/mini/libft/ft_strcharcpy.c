

unsigned int	ft_strcharcpy(char *dest, char *src, char until, unsigned int pos)
{
	unsigned int i;
	i = 0;
	if ((!dest) || (!src))
		return (0);
	while ((src[pos] != '\0' && src[pos] != until))
		dest[i++] = src[pos++];
	dest[i] = 0;
	return (++pos) ;
}
