#include "../cub3D.h"

void				parse_color_util(t_all *all, char **line, int *dst)
{
	while (**line == ' ')
		(*line)++;
	if (ft_isdigit(**line))
	{
		if(*dst != -1)
			handle_error("Too much data\n", all);
		*dst = ft_atoi(*line);
	}
	while (ft_isdigit(**line))
		(*line)++;
}

void				parse_floor(t_all *all, char *line)
{
	parse_color_util(all, &line, &all->data.flr_1);
	if (*line != ',')
		handle_error("Invalid data\n", all);
	line++;
	parse_color_util(all, &line, &all->data.flr_2);
	if (*line != ',')
		handle_error("Invalid data\n", all);
	line++;
	parse_color_util(all, &line, &all->data.flr_3);
	while (*line == ' ')
		line++;
	if (*line != '\0')
		handle_error("Invalid data format\n", all);
	all->data.flr = create_rgb(all->data.flr_1, all->data.flr_2, all->data.flr_3 );
}

void				parse_ceil(t_all *all, char *line)
{
	parse_color_util(all, &line, &all->data.ceil_1);
	if (*line != ',')
		handle_error("Invalid data\n", all);
	line++;
	parse_color_util(all, &line, &all->data.ceil_2);
	if (*line != ',')
		handle_error("Invalid data\n", all);
	line++;
	parse_color_util(all, &line, &all->data.ceil_3);
	while (*line == ' ')
		line++;
	if (*line != '\0')
		handle_error("Invalid data format\n", all);
	all->data.ceil = create_rgb(all->data.ceil_1, all->data.ceil_2, all->data.ceil_3 );
}

void				parse_path(t_all *all, char *src, char **dst)
{
	if (*dst != NULL)
		handle_error("Too much data in texture field\n", all);
	*dst = ft_strtrim(src, " ");
}
void				parse_res(t_all *all, char *line)
{
	while(*line == ' ')
		line++;
	if(ft_isdigit(*line))
	{
		if(all->data.res1 != 0)
			handle_error("Too much data in resolution\n", all);
		all->data.res1 = ft_atoi(line);
	}
	while(ft_isdigit(*line))
		line++;
	while(*line == ' ')
		line++;
	if (ft_isdigit(*line))
	{
		if(all->data.res2 != 0)
			handle_error("Too much data in resolution\n", all);
		all->data.res2 = ft_atoi(line);
	}
	while(ft_isdigit(*line))
		line++;
	while(*line == ' ')
		line++;
	if (*line != '\0')
		handle_error("Invalid resolution format\n", all);
}

void			parse_other(t_all *all, char *line)
{
	if (*line == 'R' && *(line + 1) == ' ')
		parse_res(all, line + 2);
	else if (*line == 'N' && *(1 + line) == 'O' && *(2 + line) == ' ')
		parse_path(all, line + 3, &all->data.no);
	else if (*line == 'S' && *(1 + line) == 'O' && *(2 + line) == ' ')
		parse_path(all, line + 3, &all->data.so);
	else if (*line == 'W' && *(1 + line) == 'E' && *(2 + line) == ' ')
		parse_path(all, line + 3, &all->data.we);
	else if (*line == 'E' && *(1 + line) == 'A' && *(2 + line) == ' ')
		parse_path(all, line + 3, &all->data.ea);
	else if (*line == 'F' && *(line + 1) == ' ')
		parse_floor(all, line + 2);
	else if (*line == 'C' && *(line + 1) == ' ')
		parse_ceil(all, line + 2);
	else if (*line == 'S' && *(1 + line) == ' ')
		parse_path(all, line + 2, &all->data.s);
	else if (*line != '\0')
		handle_error("Incorrect data in the header\n", all);
}