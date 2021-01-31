# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

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

int					parser(t_struct data, char **map);