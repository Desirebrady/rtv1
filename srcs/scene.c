#include "rtv1.h"

t_scene	*new_scene(void)
{
	t_scene	*s;

	s = (t_scene*)malloc(sizeof(t_scene));
	s->cam = NULL;
	s->lights = NULL;
	s->planes = NULL;
	s->spheres = NULL;
	return (s);
}

t_scene	*get_scene(void)
{
	static t_scene	*s = NULL;

	if (s == NULL)
			s = new_scene();
	return (s);
}

void	delete_scene(t_scene *s)
{
	delete_camera(s->cam);
	delete_lights(&s->lights);
	delete_planes(&s->planes);
	delete_spheres(&s->spheres);
	free(s);
}
