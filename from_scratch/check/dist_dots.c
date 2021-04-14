#include "cub3D.h"

double			dist_dots(double x, double y, double a, double b)
{
	double			dist;

	dist = sqrt(pow((x - a), 2) + pow((a - b), 2));
	return (dist);
}