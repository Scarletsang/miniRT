#include "MINIRT/camera.h"
#include "MINIRT/viewport.h"
#include <stdlib.h>

struct s_mrt_camera	*new_camera(const struct s_mrt_image *img)
{
	struct s_mrt_camera *cam;

	cam = malloc(sizeof(struct s_mrt_camera));
	if (cam == NULL)
		return (NULL);
	cam->viewport_height = 2.0;
	cam->viewport_width = img->aspect_ratio * cam->viewport_height;
	cam->focal_length = 1.0;
	cam->origin = vec3(0.0, 0.0, 0.0);
	cam->horizontal = vec3(cam->viewport_width, 0.0, 0.0);
	cam->vertical = vec3(0.0, cam->viewport_height, 0.0);
	//origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length):
	cam->lower_left_corner =
	vec3_subtract(
		vec3_subtract(
			vec3_subtract(
				cam->origin
				, vec3_divide(cam->horizontal, 2.0))
			, vec3_divide(cam->vertical, 2.0))
		, vec3(0.0, 0.0, cam->focal_length));
	return (cam);
}
