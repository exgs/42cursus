### MiniLibX(3)
# MiniLibX - Handle events

## SYNOPSYS

```C
int
mlx_loop ( void *mlx_ptr );

int
mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

int
mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

int
mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

int
mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );
```

## EVENTS
    X-Window 및 MacOSX 그래픽 시스템은 모두 양방향입니다. 한편으로 프로그램은 픽셀, 이미지 등을 표시하기 위해 화면에 명령을 보냅니다. 반면 화면에 연결된 키보드와 마우스에서 정보를 얻을 수 있습니다. 이를 위해 프로그램은 키보드 또는 마우스에서 "이벤트"를 수신합니다.

## DESCRIPTION
    이벤트를 수신하려면 mlx_loop ()를 사용해야합니다. 이 함수는 반환되지 않습니다. 이벤트를 기다린 다음이 이벤트와 관련된 사용자 정의 함수를 호출하는 무한 루프입니다. 연결 식별자 mlx_ptr (mlx 매뉴얼 참조)라는 단일 매개 변수가 필요합니다.
    
    다음 세 가지 이벤트에 서로 다른 기능을 할당 할 수 있습니다.
        -키를 눌렀습니다.
        -마우스 버튼을 눌렀습니다.
        -창의 일부를 다시 그려야합니다 (이를 "노출"이벤트라고하며이를 처리하는 것은 프로그램의 작업입니다).
    **각 창**은 동일한 이벤트에 대해 다른 기능을 정의 할 수 있습니다.
    
    mlx_key_hook (), mlx_mouse_hook () 및 mlx_expose_hook ()의 세 가지 함수는 정확히 동일한 방식으로 작동합니다. funct_ptr은 이벤트가 발생할 때 호출 할 함수에 대한 포인터입니다.
    이 할당은 win_ptr 식별자로 정의 된 창에만 적용됩니다. 매개 변수 주소는 호출 될 때마다 함수에 전달되며 필요한 매개 변수를 저장하는 데 사용해야합니다.
    
    mlx_loop_hook () 함수의 구문은 이전 구문과 동일하지만 이벤트가 발생하지 않으면 주어진 함수가 호출됩니다.
    이벤트를 포착하면 MiniLibX는 고정 매개 변수로 해당 함수를 호출합니다.
    - expose_hook (void * param);
    - key_hook (int keycode, void * param);
    - mouse_hook (int button, int x, int y, void * param);
    - loop_hook (void * param);
    
    이러한 함수 이름은 임의적입니다. 여기서는 이벤트에 따라 매개 변수를 구별하는 데 사용됩니다. 이러한 기능은 MiniLibX의 일부가 아닙니다.
    param은 mlx _ * _ hook 호출에 지정된 주소입니다. 이 주소는 MiniLibX에서 사용하거나 수정하지 않습니다. 키 및 마우스 이벤트에서 추가 정보가 전달됩니다. 키코 드는 어떤 키를 눌렀는지 알려줍니다. (X11 : 포함 파일 "keysymdef.h"찾기, MacOS : 작은 소프트웨어를 만들고 직접 확인), (x, y) 창에서 마우스 클릭의 좌표이며 버튼은 어떤 마우스 버튼을 눌렀는지 알려줍니다.

## GOING FURTHER WITH EVENTS


MiniLibX는 모든 유형의 이벤트에 대한 훨씬 일반적인 액세스를 제공합니다.

`mlx.h` include는`mlx _ * _ hook` 함수가 작동하는 것과 동일한 방식으로`mlx_hook ()`을 정의합니다.
이벤트 및 마스크 값은 X11 포함 파일 'X.h'에서 가져옵니다 (MacOSX의 경우에도 호환성을 위해).

[mlx_int_param_event.c] (https://github.com/qst0/ft_libgfx/blob/master/minilibx_X11_sources/mlx_int_param_event.c)의 소스 코드를 참조하세요.
MiniLibX가 특정 이벤트에 대해 자체 함수를 호출하는 방법을 알아보십시오.       

## SEE ALSO

[mlx(3)](man_mlx.md), [mlx_new_window(3)](man_mlx_new_window.md),
[mlx_pixel_put(3)](man_mlx_pixel_put.md), [mlx_new_image(3)](man_mlx_new_image.md)

## AUTHOR

Copyright ol@ - 2002-2015 - Olivier Crouzet

### MiniLibX(3)