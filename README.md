# miniRT

A Raytracing engine written in C

## Default settings

All the default configutations for debugging is inside the directory default.

## Architecture

### 1. Command-line parser

Parses mandatory scene_file location and optional command line option such as:

```bash
./miniRT scene.rt --anti-alias=3 # anti aliasing sample count
./miniRT scene.rt --depth=5 # maximum recusion depth for ray bouncing
./miniRT scene.rt --threads=3
./miniRT scene.rt --max-distance=300 # maximum world distance (in world space unit), dont render after such distance
./miniRT scene.rt --ppm=output.ppm # switch to rendering using the ppm renderer instead of MLX42
```

Returns a `struct s_mrt_renderer_config`.

### 2. Scene file parser

Parses the .rt file that specify every objects, lights and camera in the scene.

Returns a `struct s_mrt_scene`.

### 3. World

Scene represents the pure logical data, the minimum data needed to describe an entity in the world space. To render the scene, all of the scene objects has to be wrapped into a world object that contains extra data to ease the rendering process.

The `mrt_world_from_scene` function wraps each `union u_scene_entry_object` inside the `struct s_mrt_scene` produced by the previous parser into `union u_world_entry_object` and store it inside a `struct s_mrt_world`.

In the process of creating world objects, it might need some meta-data, which is described inside the `struct s_mrt_world_options`.

After this process, the `struct s_mrt_scene` is freed but each scene object is stored inside its corresponding world object. The `struct s_mrt_world` is created.

### 4. Renderer

Reads the `struct s_mrt_renderer_config` produced by the command line parser to determine which renderer to use and how to render.

### 5. Ray creation

Shoot a ray to each pixel. Optionally, depending on the anti-aliasing sample count stated inside the `struct s_mrt_renderer_config`, it will shoot the amount of rays through each pixels. The precise location that the ray will be shoot to is determined by probablistic function.

### 6. Ray Intersection

Calculate the intersection point of a ray on an object.

### 7. Ray hits

Calculate the normal of the intersection point on that object.

Send a ray to each light source, see if it hits any object, determine light intensity of all the rays that did not hit any objects.

Calculate the dot product of every missed ray with a weight of the light intensity of that ray to the normal of that intersection point:

Cn = color_of_one_ray(intensity, ray_to_light, normal) = dot(intensity * ray_to_light, normal)

Color of the pixel = (sum(C1, C2, ... Cn) / n) * object_texture_color

### 8. Ray misses

Coloring the misses rays.

### 9. Transformation and rotation

4 kinds of 4x4 matrix is needed to describe different kind of vector transformation:

1. Transformation matrix
2. Shear matrix
3. Scale matrix
4. Rotation matrix

Quaternions might ease the creation of rotation matrix.

## Extra

GLSL

mesh = [array of points]
color vertex_shader(point, world_info) // world_info can be texture or anything

color_of_each_vertex = map(mesh, vectex_shader) // aray of colors
color_of_each_pixel = interpolation(color_of_each_vertex)

color fragment_shader(color_of_one_pixel, world_info)
result = map(color_of_each_pixel, fragment_shader)
