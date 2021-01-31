# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"


typedef struct		s_struct
{
	int 			resolution;
	int 			no;
	int 			so;
	int 			we;
	int 			ea;
	int 			floor;
	int 			ceil;
}					t_struct;

int					parser(t_struct *data, char *line);
int					get_next_line(int fd, char **line);
