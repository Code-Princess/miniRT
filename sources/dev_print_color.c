#include <stdio.h>
#include "../includes/color.h"

void	print_color(t_color color)
{
	printf("color: RED %f, GREEN %f, BLUE %f\n", color.colors_float[RED], color.colors_float[GREEN], color.colors_float[BLUE]);
}
