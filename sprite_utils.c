#include "cub3D.h"

void			init_spr(t_all *all)
{

}

void			hide_spr(t_all *all)
{
	int				i;

	i = 0;
	while(i < all->spr_count)
	{
		all->spr_arr[i].tag_vis = 0;
		i++;
	}
}

int				get_color(t_image *image, int x, int y)
{
	char		*dst;
	int			res;

	if (x < image->w && y < image->h && x > 0 && y > 0)
	{
		dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
		res = (*(int*)dst);
		return(res);
	}
	return (0);
}

t_pos 					v_sub(t_pos v1, t_pos v2)
{
	t_pos 		res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	return (res);
}

t_pos 					project_spr(t_pos m, t_pos n, t_pos d0, t_pos dot)
{
	t_pos 		proj;
	t_pos 		sub_dot;
	double		det;

	sub_dot = v_sub(dot, d0);
	det = m.x * n.y - m.y * n.x;
	proj.x = 1 / det * (n.y * sub_dot.x - n.x * sub_dot.y);
	proj.y = 1 / det * (-m.y * sub_dot.x + m.x * sub_dot.y);
	return (proj);
}

void					visualize_sprite(t_all *all, t_sprite sprite, t_pos proj_coor)
{
	double				j;
	double				i;
	t_pos				s_dot;
	int					color;

	i = 0;
	sprite.width = fabs(all->data.res2 / proj_coor.y);
	sprite.start.x = proj_coor.x - sprite.width / 2;
	sprite.end.x = proj_coor.x + sprite.width / 2;

	sprite.start.y = all->data.res2 / 2 - all->data.res2 / proj_coor.y / 2 - 1;
	sprite.end.y = all->data.res2 / 2 + all->data.res2 / proj_coor.y / 2;
	i = sprite.start.x;
	all->s.s.w = 64;
	all->s.s.h = 64;
	while (i < sprite.end.x)
	{
		s_dot.x = (i - sprite.start.x) / sprite.width * all->s.s.w; // move get_address to init_textures
		j = sprite.start.y;
		while (j < sprite.end.y)
		{
			s_dot.y = (j - sprite.start.y) / sprite.width * all->s.s.h;
			color = get_color((t_image *) &all->s.s.img, (int)s_dot.x, (int)s_dot.y);
			my_mlx_pixel_put(all, (int)i, (int)j, color);
			j++;
		}
		i++;
	}
}

void 					bubble_sort(t_all *all)
{
	int					i;
	int					j;
	t_sprite 			temp;

	i = 0;
	while(i < all->spr_count)
	{
		j = all->spr_count - 1;
		while(j > i)
		{
			if(all->spr_arr[j - 1].dist < all->spr_arr[j].dist)
			{
				temp = all->spr_arr[j - 1];
				all->spr_arr[j - 1] = all->spr_arr[j];
				all->spr_arr[j] = temp;
			}
			j--;
		}
		i++;
	}
}

void					count_dist(t_all *all)
{
	double				dist_to_spr;
	int					i;
	int					j;

	i = 0;
	j = 0;
	while (i < all->spr_count)
	{
		dist_to_spr = len_of_vec(all->player.pos.x - all->spr_arr[i].coord.x, all->player.pos.y - all->spr_arr[i].coord.y);
		all->spr_arr[i].dist = dist_to_spr;
		i++;
	}
}

void					draw_sprite(double *z_buf, t_all *all)
{
	t_pos 				proj_coor;
	double				tmp_x;

	count_dist(all);
	bubble_sort(all);
	proj_coor = project_spr(all->player.plane, all->player.dir, all->player.pos, all->spr_arr[0].coord);
	double h = fabs(all->data.res2 / proj_coor.y);
	proj_coor.x = (double)all->data.res1 / 2 * (1 + proj_coor.x / proj_coor.y) - h / 2;
	visualize_sprite(all, all->spr_arr[0], proj_coor);
}

/*
 * we initialize a sprite, then we add it to the spr_array. We include info about its coordinates.
 */
void 					add_spr_to_arr(t_all *all, t_sprite **arr_m)
{
	t_sprite			*arr;
	int 				i;
	int 				x;
	int 				y;
	t_sprite			spr;

	arr = (t_sprite *)malloc(all->spr_count*sizeof(t_sprite)); // we have to free this pointer
	x = 0;
	y = 0;
	i = 0;
	while (y < all->map.lines)
	{
		x = 0;
		while (all->map.map[y][x] != '\0')
		{
			if (all->map.map[y][x] == '2')
			{
				spr.coord.x = x + 0.5;
				spr.coord.y = y + 0.5;
				arr[i] = spr;
				i++;
			}
			x++;
		}
		y++;
	}
	*arr_m = arr;
}