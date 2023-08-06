#include "MINIRT/ray.h"
#include <stdio.h>
#include <stdlib.h>

t_mrt_ray	ray_create(t_mrt_point3d origin, t_mrt_direction3d direction)
{
	return ((t_mrt_ray){origin, direction});
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
	return (vec3_add(ray->orig, \
		vec3_multiply(ray->dir, t)));
}

void	ray_ppm(void)
{
	struct s_mrt_camera	*cam;

	cam = mrt_camera_default();
	if (!cam)
		return ;
	ray_ppm_loop(cam);
}

void	ray_ppm_loop(struct s_mrt_camera *cam)
{
	int				j;
	int				i;
	double			u;
	double			v;
	t_mrt_color		pixel_color;
	t_mrt_ray		ray;

	printf("P3\n%d %d\n255\n", img->image_width, img->image_height);
	j = img->image_height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < img->image_width)
		{
			u = (double) i / (img->image_width - 1);
			v = (double) j / (img->image_height - 1);
			ray = ray_create(cam->origin, \
				vec3_subtract(\
					vec3_add(\
						vec3_add(\
							cam->lower_left_corner, \
							vec3_multiply(cam->horizontal, u)), \
						vec3_multiply(cam->vertical, v)), \
					cam->origin));
			pixel_color = ray_color(&ray);
			vec3_color_write(pixel_color);
			i++;
		}
		j--;
	}
}