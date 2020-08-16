** dealing with Events

int mlx_mouse_hook (void *win_ptr, int (\*funct_ptr)(), void *param);

int mlx_key_hook (void \*win_ptr, int (*funct_ptr)(), void \*param);

int mlx_expose_hook (void \*win_ptr, int (*funct_ptr)(), void \*param);



```objective-c
void mlx_expose_hook(mlx_win_list_t *win_ptr, int (*funct_ptr)(), void *param)
{
  [(id)(win_ptr->winid) setEvent:12 andFunc:funct_ptr andParam:param];
}

void mlx_key_hook(mlx_win_list_t *win_ptr, int (*funct_ptr)(), void *param)
{
  [(id)(win_ptr->winid) setEvent:3 andFunc:funct_ptr andParam:param];
}

void mlx_mouse_hook(mlx_win_list_t *win_ptr, int (*funct_ptr)(), void *param)
{
  [(id)(win_ptr->winid) setEvent:4 andFunc:funct_ptr andParam:param];
}

void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*funct_ptr)(), void *param)
{
  [(id)(win_ptr->winid) setEvent:x_event andFunc:funct_ptr andParam:param];
}

```

int mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);

int mlx_loop (void *mlx_ptr);



** hook funct are called as follow :

**  expose_hook(void *param);

**  key_hook(int keycode, void *param);

**  mouse_hook(int button, int x,int y, void *param);

**  loop_hook(void *param);



** Usually asked...

int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

void  *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);

void  *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

void  *mlx_png_file_to_image(void *mlx_ptr, char *file, int *width, int *height);



int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int mlx_destroy_image(void *mlx_ptr, void *img_ptr);



generic hook system for all events, and minilibX functions that can be hooked. Some macro and defines from X11/X.h are needed here.



int mlx_hook(void \*win_ptr, int x_event, int x_mask, int (\*funct)(), void *param);



int   mlx_mouse_hide();

int   mlx_mouse_show();

int   mlx_mouse_move(void *win_ptr, int x, int y);

int   mlx_mouse_get_pos(void *win_ptr, int *x, int *y);



int mlx_do_key_autorepeatoff(void *mlx_ptr);

int mlx_do_key_autorepeaton(void *mlx_ptr);

int mlx_do_sync(void *mlx_ptr);