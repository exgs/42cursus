# MiniLibX(3)

# MiniLibX - Simple Graphical Interface Library for students

## SYNOPSYS

```C
#include  <mlx.h>

void  *
mlx_init();
```

## DESCRIPTION

MiniLibX는 X-Window / Cocoa 프로그래밍 지식이 없어도 그래픽 소프트웨어를 쉽게 만들 수있는 방법입니다.
간단한 창 생성, 그리기 도구, 이미지 및 기본 이벤트 관리를 제공합니다.

## BSD/LINUX X-WINDOW CONCEPT

X-Window는 Unix를위한 네트워크 지향 그래픽 시스템입니다. 두 가지 주요 부분을 기반으로합니다.

한쪽에서는 소프트웨어가 화면에 무언가를 그리거나 키보드 및 마우스 항목을 가져 오려고합니다.

반면에 X-Server는 화면, 키보드 및 마우스를 관리합니다 ( "디스플레이"라고도 함).

도면 주문을 보내려면이 두 엔티티간에 네트워크 연결이 설정되어야합니다.
(소프트웨어에서 X-Server로) 및 키보드 / 마우스 이벤트 (X-Server에서 소프트웨어로).

## MACOS CONCEPT
MacOSX 운영 체제는 화면 (또는 "디스플레이")에 대한 그래픽 액세스를 처리합니다.

한쪽에서는 소프트웨어가 화면에 무언가를 그리거나 키보드 및 마우스 항목을 가져 오려고합니다.

다른 한편으로는 화면, 윈도우 시스템, 키보드 및 마우스를 처리하는 기본 MacOSX 그래픽 프레임 워크입니다.

이 두 개체 간의 연결이 설정되어야합니다.

## INCLUDE FILE

MiniLibX API를 올바르게 사용하려면`mlx.h`가 포함되어야합니다.

함수 프로토 타입 만 포함되며 구조가 필요하지 않습니다.  
(It only contains function prototypes, no structure is needed.)

## LIBRARY FUNCTIONS

먼저 소프트웨어와 디스플레이 간의 연결을 초기화해야합니다.

이 연결이 설정되면 다른 MiniLibX 기능을 사용하여 그래픽 명령을 보낼 수 있습니다.
"이 창에 노란색 픽셀을 그리고 싶습니다."또는 "사용자가 키를 눌렀습니까?"

`mlx_init ()`함수는이 연결을 생성합니다.
매개 변수가 필요하지 않으며 라이브러리 루틴에 대한 추가 호출에 사용되는 void * 식별자(identifier)를 반환합니다.

* 다른 모든 MiniLibX 기능은 다음 매뉴얼 페이지에 설명되어 있습니다.

  * [mlx_new_window] (man_mlx_new_window.md) : 창 관리

  * [mlx_pixel_put] (man_mlx_pixel_put.md) : 창 안에 그리기

  * [mlx_new_image] (man_mlx_new_image.md) : 이미지 조작

  * [mlx_loop] (man_mlx_loop.md) : 키보드 또는 마우스 이벤트 처리

BSD / Linux 및 X-Window에서 MinilibX 연결
MiniLibX 기능을 사용하려면 소프트웨어를 다음과 연결해야합니다.
MiniLibX 라이브러리 자체를 포함한 여러 라이브러리. 이것을하기 위해,
연결시 다음 인수를 추가하기 만하면됩니다.
       
`-lmlx -lXext -lX11`

`-L` 플래그를 사용하여 이러한 라이브러리의 경로를 지정해야 할 수도 있습니다.


## LINKING Minilibx on MACOSX

MiniLibX 기능을 사용하려면 소프트웨어를 MiniLibX 라이브러리 및 여러 시스템 프레임 워크와 연결해야합니다.

`-lmlx -framework OpenGL -framework AppKit`

`-L` 플래그를 사용하여 MiniLibX 라이브러리에 대한 경로를 지정해야 할 수도 있습니다.

## RETURN VALUES

'mlx_init ()'가 그래픽 시스템에 대한 연결 설정에 실패하면 NULL을 반환하고,
그렇지 않으면 널이 아닌 포인터가 연결 식별자로써 리턴됩니다.

## SEE ALSO

[mlx_new_window(3)](man_mlx_new_window.md), [mlx_pixel_put(3)](man_mlx_pixel_put.md),
[mlx_new_image(3)](man_mlx_new_image.md), [mlx_loop(3)](man_mlx_loop.md)

## AUTHOR

Copyright ol@ - 2002-2015 - Olivier Crouzet

# MiniLibX(3)
