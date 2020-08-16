### MiniLibX(3)

# MiniLibX - Drawing inside windows

## SYNOPSYS

```C
int
mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );

int
mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
```

## DESCRIPTION

`mlx_pixel_put ()`함수는`win_ptr` 창에 정의 된 픽셀을 그립니다.
`(x, y)`좌표와 지정된 색상을 사용합니다.

원점`(0, 0)`은 창의 왼쪽 상단 모서리입니다.
`x`와`y` 축은 각각 오른쪽 방향과 아래쪽 방향을 가리 킵니다.

연결 식별자`mlx_ptr`이 필요합니다 ([mlx man page] (man_mlx.md) 참조).

`mlx_string_put ()`의 매개 변수는 동일한 의미를 갖습니다.
단순한 픽셀 대신 지정된 문자열이`(x, y)`에 표시됩니다.

두 기능 모두 지정된 창 밖에는 아무것도 표시 할 수 없습니다.
선택한 창 앞에 다른 창에 표시하지도 않습니다.

## COLOR MANAGEMENT

색상 매개 변수에는 정수 유형이 있습니다.

표시된 색상은 정의 된 체계에 따라이 정수로 인코딩되어야합니다.

표시 가능한 모든 색상은 빨간색, 녹색 및 파란색의 3 가지 기본 색상으로 나눌 수 있습니다.

0-255 범위의 세 가지 관련 값은 원래 색상을 만들기 위해 각 색상이 얼마나 혼합되었는지를 나타냅니다.

올바른 색상을 표시하려면이 세 가지 값을 정수 내에 설정해야합니다.
이 정수의 최하위 바이트 3 개는 아래 그림과 같이 채워집니다.

                | 0 | R | G | B | 색상 정수
                + --- + --- + --- + --- +

정수를 채우는 동안 엔디안 문제를 피해야합니다. "파란색" 바이트는 항상 최하위 항목이어야합니다.

## SEE ALSO

[mlx(3)](man_mlx.md), [mlx_new_window(3)](man_mlx_new_window.md),
[mlx_new_image(3)](man_mlx_new_image.md), [mlx_loop(3)](man_mlx_loop.md)

## AUTHOR

Copyright ol@ - 2002-2015 - Olivier Crouzet

### MiniLibX(3)
