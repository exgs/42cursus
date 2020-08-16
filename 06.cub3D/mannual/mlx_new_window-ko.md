### wMiniLibX(3)

# MiniLibX - Managing windows

## SYNOPSYS

```C
void *
mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

int
mlx_clear_window ( void *mlx_ptr, void *win_ptr );

int
mlx_destroy_window ( void *mlx_ptr, void *win_ptr );
```

## DESCRIPTION

`mlx_new_window ()`함수는`size_x` 및`size_y` 매개 변수를 사용하여 크기를 결정하고 `title`을 창의 제목 표시 줄에 표시 할 텍스트로 사용하여 화면에 새 창을 만듭니다.

`mlx_ptr` 매개 변수는`mlx_init ()`에서 반환하는 연결 식별자입니다 ([mlx man page] (man_mlx.md) 참조). `mlx_new_window ()`는 다른 MiniLibX 호출에서 사용할 수있는`void *`창 식별자를 반환합니다.

MiniLibX는 임의의 수의 개별 창을 처리 할 수 있습니다.

`mlx_clear_window ()`및`mlx_destroy_window ()`는 각각 지정된 창을 지우고 (검은 색) 삭제합니다. 둘 다 동일한 매개 변수를가집니다.`mlx_ptr`은 화면 연결 식별자이고`win_ptr`은 창 식별자입니다.  
`win_ptr = mlx_new_window();`

##RETURN VALUES

만약`mlx_new_window ()`가 새 창을 만들지 못하면 (왜냐면)
'NULL', 그렇지 않으면 널이 아닌 포인터가 창 식별자로 반환됩니다. `mlx_clear_window` 및`mlx_destroy_window`는 현재 아무것도 반환하지 않습니다.

## SEE ALSO

[mlx(3)](man_mlx.md), [mlx_pixel_put(3)](man_mlx_pixel_put.md), [mlx_new_image(3)](man_mlx_new_image.md), [mlx_loop(3)](man_mlx_loop.md)

## AUTHOR

Copyright ol@ - 2002-2015 - Olivier Crouzet

### MiniLibX(3)
