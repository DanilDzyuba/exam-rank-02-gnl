#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
	int len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}

char *add_to_str(char **s, char c)
{
	char *new;
	int i;
	int len;

	i = 0;
	len = ft_strlen(*s);
	if(!(new = malloc(sizeof(char) * len + 2)))
		return (NULL);
	while (i < len)
	{
		new[i] = (*s)[i];
		i++;
	}
	free(*s);
	new[i] = c;
	new[++i] = '\0';
	return (new);
}

int get_next_line(char **line)
{
	char *s;
	char c[1];
	int readed;

	if (read(0, 0, 0) == -1)
		return (-1);
	s = malloc(1);
	*s = '\0';
	readed = 1;
	while (readed && (readed = read(0, c,1 )))
	{
		if (c[0] == '\n')
			break ;
		if (!(s = add_to_str(&s, c[0])))
			return (-1);
	}
	*line = s;
	if (!readed)
		return (0);
	return (1);
}

int main()
{
	char *line;
	int ret;
	int len;
	char n = '\n';

	while((ret = get_next_line(&line)) >= 0)
	{
		len = ft_strlen(line);
		write(1, line, len);
		write(1, &n, 1);
		free(line);
		if (!ret)
			break ;
	}
	return 0;
}