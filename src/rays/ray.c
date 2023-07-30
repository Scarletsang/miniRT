#include "MINIRT/ray.h"
#include <stdio.h>
#include <stdlib.h>

t_mrt_ray	*ray_create(t_mrt_point3d origin, t_mrt_direction3d direction)
{
	t_mrt_ray	*ray;

	ray = malloc(sizeof(t_mrt_ray));
	ray->orig = origin;
	ray->dir = direction;
	return (ray);
}

t_mrt_color	ray_color(t_mrt_ray	*ray)
{
	t_mrt_direction3d	unit_direction;
	double	t;
	t_mrt_color	tmp;
	t_mrt_color	tmp2;

	unit_direction = vec3_normalize(ray->dir);
	t = 0.5 * (unit_direction.y + 1.0);
	tmp = vec3_multiply(vec3(1.0, 1.0, 1.0), (1.0 - t));
	tmp2 = vec3_multiply(vec3(0.5, 0.7, 1.0), t);
	return (vec3_add(tmp, tmp2));
}

t_mrt_point3d	ray_at(t_mrt_ray *ray, double t)
{
	t_mrt_point3d	tmp;

	tmp = vec3_multiply(ray->dir, t);
	return (vec3_add(ray->orig, tmp));
}

void	ray_ppm(void)
{
	t_mrt_camera	*cam;
	const t_mrt_image		*img = new_image();

	cam = new_camera(img);
	ray_ppm_loop(cam, img);
}

void	ray_ppm_loop(t_mrt_camera *cam, const t_mrt_image *img)
{
	int				j;
	int				i;
	double			u;
	double			v;
	t_mrt_color		pixel_color;
	t_mrt_ray		*ray;

	printf("P3\n%d %d\n255\n", img->image_width, img->image_height);
	j = img->image_height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < img->image_width)
		{
			u = (double) i / (img->image_width - 1);
			v = (double) j / (img->image_height - 1);
			ray = ray_create(cam->origin, vec3_subtract(vec3_add(vec3_add(cam->lower_left_corner, vec3_multiply(cam->horizontal, u)), vec3_multiply(cam->vertical, v)), cam->origin));
			pixel_color = ray_color(ray);
			vec3_color_write(pixel_color);
			i++;
		}
		j--;
	}
}