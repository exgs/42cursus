1. `04`: ButtonPress, `05`: ButtonRelease    
   `int mouse_button(int button, void *param)` (키보드 press와 달리 꾹 누르는 것을 인지하지 못함)
2. `06`: MotionNotify  
   예외적으로 다음과 같은 프로토타입을 가진다.  
   `int function_name(int x, int y, void *param)`

---

mlx_loop_hook () 함수의 구문은 이전 구문과 동일하지만 이벤트가 발생하지 않으면 주어진 함수가 호출됩니다.
이벤트를 포착하면 MiniLibX는 고정 매개 변수로 해당 함수를 호출합니다.

- expose_hook (void * param);
- Key_hook(int key code, void *param);
- mouse_hook (int button, int x, int y, void * param);
- loop_hook (void * param);



mlx_clear_window(data.mlx, data.win); window창의 모든 pixel을 초기화 시킴.  
이 경우 mlx_pixel_put() 으로 찍었던 픽셀은 저장되지 않기 때문에 완전히 사라진다.  
반면에 image는 그 내용이 저장되어 있기 때문에 mlx_put_image_to_window로 복원할 수 있다.  
mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0); 이미지가 window창에 보여지게 함.  
event가 발생하지 않는 경우 mlx_loop()가 실행중이라면, mlx_loop_hook(img.mlx, loop_hook_easy, &img);  
가 계속 돌아가게 함

---

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

설명서에는 int형으로 프로토타입을 명시해놓았지만, mlx_hook 모두 void 형이다. return 값이 존재하지 않는다.  

```c
//opengl mlx.h
int	mlx_do_sync(void *mlx_ptr);

//mms mlx.h
#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3
int	mlx_sync(int cmd, void *param);
/*
** image_writable can loop forever if no flush occurred. Flush is always done by mlx_loop.
** cmd_completed first flush then wait for completion.
** mlx_do_sync equals cmd_completed for all windows.
** cmd is one of the define, param will be img_ptr or win_ptr accordingly
*/
```

