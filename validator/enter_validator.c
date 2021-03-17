#include "../cub3D.h"

int					valid_res(char *line)
{
	while (*line == ' ')
		line++;
	while (ft_isdigit(line))
		line++;

}

int					validator(char *line)
{
	if (*line == 'R' && *(1 + line) == ' ')
	{
		valid_res(2 + line);

	}
}


int					enter_validator(t_all *all, char *file_name)
{
	int				fd;
	char			*line;

	fd = open(file_name, O_RDONLY);
	while(get_next_line(fd, &line))
	{
		validator(line);
	}
}