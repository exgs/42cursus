### MiniLibX(3)

# MiniLibX - Manipulating images

## SYNOPSYS
```C
void *
mlx_new_image ( void *mlx_ptr, int width, int height );

char *
mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
int endian = 0;
int
mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );

unsigned int
mlx_get_color_value ( void *mlx_ptr, int color );

void *
mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );

void *
mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );

int
mlx_destroy_image ( void *mlx_ptr, void *img_ptr );
```

## DESCRIPTION

`mlx_new_image ()`는 메모리에 새 이미지를 만듭니다.

나중에이 이미지를 조작하는 데 필요한`void *`식별자를 반환합니다.

`width` 및`height` 매개 변수를 사용하여 생성 할 이미지의 크기를 설정한다. `mlx_ptr` 연결 식별자가 필요하다. ([mlx 매뉴얼] (man_mlx.md) 참조).

사용자는 이미지 내부에 그릴 수 있습니다 ([아래 참조] (# storing-color-inside-images)),
언제든지 지정된 창에 이미지를 덤프(복사해 가서 저장)하여 화면에 표시 할 수 있습니다.

이것은`mlx_put_image_to_window ()`를 사용하여 수행됩니다.

디스플레이에 연결하려면 여기에 세 개의 식별자가 필요합니다.
사용할 창 및 이미지 (각각`mlx_ptr`,`win_ptr` 및`img_ptr`).
`(x, y)`좌표는 창에서 이미지를 배치해야하는 위치를 정의합니다.   

`mlx_get_data_addr ()`은 생성 된 이미지에 대한 정보를 반환하여 사용자가 나중에 수정할 수 있도록합니다.`img_ptr` 매개 변수는 사용할 이미지를 지정합니다.

다음 세 개의 매개 변수는 세 가지 다른 유효한 정수의 주소 여야합니다.

1. `bits_per_pixel`은 픽셀 색상을 나타내는 데 필요한 비트 수로 채워집니다.
   (이미지의 깊이라고도 함).

2. `size_line`은 이미지 한 줄을 메모리에 저장하는 데 사용되는 바이트 수입니다.
   이 정보는 이미지의 한 줄에서 다른 줄로 이동하는 데 필요합니다.

3. `endian` tells you wether the pixel color in the image needs to be stored in:<br>
   little `(endian == 0)`, or big `(endian == 1)`.  
   endian`은 이미지의 픽셀 색상을 저장할 위치를 알려줍니다. <br>
   little`(endian == 0)`또는 big`(endian == 1)`.

`mlx_get_data_addr`는 이미지가 저장되는 메모리 영역의 시작을 나타내는`char *`주소를 반환합니다.  

이 주소에서 첫 번째`bits_per_pixel` 비트는 이미지의 첫 번째 줄에있는 첫 번째 픽셀의 색상을 나타냅니다.

'bits_per_pixel'비트의 두 번째 그룹은 첫 번째 줄의 두 번째 픽셀을 나타냅니다.

주소에`size_line`을 추가하여 두 번째 줄의 시작 부분을 가져옵니다. 그런 식으로 이미지의 모든 픽셀에 도달 할 수 있습니다.

`mlx_destroy_image`는 주어진 이미지 (`img_ptr`)를 파괴합니다.

## STORING COLOR INSIDE IMAGES

디스플레이에 따라 픽셀 색상을 저장하는 데 사용되는 비트 수가 변경 될 수 있습니다.

사용자는 일반적으로 RGB 모드에서 색상을 나타냅니다.
각 구성 요소에 대해 1 바이트 사용합니다.([mlx_pixel_put 설명서] (man_mlx_pixel_put.md) 참조).

이미지의 bits_per_pixel 요구 사항에 맞게 변환해야합니다.
그래픽 시스템에서 색상을 이해할 수 있도록합니다.
이것이`mlx_get_color_value ()`함수의 목적입니다.
표준 RGB 색상 매개 변수를 취하고 부호없는 int 값을 리턴합니다.

이 값의`bits_per_pixel` 최하위 비트는 이미지에 저장할 수 있습니다.

최하위 비트 위치는 로컬 컴퓨터의 엔디안에 따라 다릅니다.

이미지의 엔디안 (실제로 원격 X11 디스플레이 용 X-Server 컴퓨터의 엔디안)이 다른 경우
로컬 엔디안에서 값을 사용하기 전에 값을 변환해야합니다.

## XPM IMAGES

`mlx_xpm_to_image ()`및`mlx_xpm_file_to_image ()`함수는 동일한 방식으로 새 이미지를 생성합니다.
사용되는 함수에 따라 지정된`xpm_data` 또는`filename`을 사용하여 채 웁니다.
MiniLibX는 표준 Xpm 라이브러리를 사용하여 xpm 이미지를 처리하지 않습니다. 모든 유형의 xpm 이미지를 읽지 못할 수 있습니다. 그러나 투명성을 처리합니다.       

## RETURN VALUES

이미지를 생성하는 세 가지 함수`mlx_new_image ()`,`mlx_xpm_to_image ()`및
`mlx_xpm_file_to_image ()`는 오류가 발생하면`NULL`을 반환합니다. 그렇지 않으면 null이 아닌 값을 반환합니다.
포인터를 이미지 식별자로 사용합니다.

## SEE ALSO

[mlx(3)](man_mlx.md), [mlx_new_window(3)](man_mlx_new_window.md),
[mlx_pixel_put(3)](man_mlx_pixel_put.md), [mlx_loop(3)](man_mlx_loop.md)

## AUTHOR

Copyright ol@ - 2002-2015 - Olivier Crouzet

### MiniLibX(3)
