char *ft_trim(char *str, char c)
{
	char	*tmp;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	//freeeeeeeeee meeeeeeeeee
	tmp = ft_calloc(ft_strlen(str), sizeof(char));
	while (str[i])
	{
		if (str[i] != c)
			tmp[j++] = str[i];
		i++;
	}
	return (tmp);
}

t_answer	ft_is_a_match(char *keyword, char *input)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(input);
	if (input == NULL)
		return (NO);
	tmp = ft_trim(input, ' ');
	if (ft_strlen(keyword) != ft_strlen(tmp))
	{
		free(tmp);
		return (NO);
	}
	while (i < len)
	{
		if (keyword[i] == tmp[i])
			i++;
		else
		{
			free(tmp);
			return (NO);
		}
	}
	free(tmp);
	return (YES);
}
