#include <stdio.h>

#include "../includes/objects.h"

void	print_plane(t_object *plane)
{
	printf("print plane in find_plane_hitpt:\n");
	printf("position: ");
	print_tuple(plane->position);
	printf("normal_vec: ");
	print_tuple(plane->s_plane.normal_vec);
	printf("color: ");
	print_color(plane->color);
}
