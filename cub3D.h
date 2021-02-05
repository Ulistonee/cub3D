# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
#define VALID_SYMBOLS "102 NESW"


typedef struct		s_struct
{
	int 			res1;
	int 			res2;
	char 			*no;
	char 			*so;
	char 			*we;
	char 			*ea;
	int 			flr_1;
	int 			flr_2;
	int 			flr_3;
	int 			ceil_1;
	int 			ceil_2;
	int 			ceil_3;
}					t_struct;

typedef struct		s_map
{
	char 			**map;
}					t_map;


typedef struct		s_all
{
	t_map			map;
	t_struct		data;
}					t_all;

int					parse_other(t_struct *data, char *line);
int 				parse_map(t_map *map, char *line);
int					get_next_line(int fd, char **line);
int 				is_map(char *line);