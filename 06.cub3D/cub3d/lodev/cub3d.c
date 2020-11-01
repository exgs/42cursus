#include "cub3d.h"
#include "libft.h"
#include "config.h"
#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

int main()
{
	
	double posX = 22, posY = 12;
	double dirX = -1, dirY = 0; //do not change
	double planeX = 0, planeY = 0.66; //do not change
	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame

	int w = 1000; //1000개의 광선
	while(!done())
	{
		for(int x = 0; x < w; x++)
		{
			double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
			double rayDirX = dirX + planeX * cameraX;
			double rayDirY = dirY + planeY * cameraX;

			// 내가 추가한 변수 rayDir(x,y)의 방향벡터의 길이를 1로 만듦
			double rayDirX_one = rayDirX / sqrt(rayDirX * rayDirX + rayDirY * rayDirY);
			double rayDirY_one = rayDirY / sqrt(rayDirX * rayDirX + rayDirY * rayDirY);	

			/*하나의 빛에 대해서*/
			//which box of the map we're in
      		int mapX = (int)posX;
      		int mapY = (int)posY;

      		//length of ray from current position to next x or y-side
      		double sideDistX;
      		double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : abs(1 / rayDirX_one));
      		double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : abs(1 / rayDirY_one));
      		double perpWallDist;
			// double fishDist;
			// double verticalDist;

      		//what direction to step in x or y-direction (either +1 or -1)
      		int stepX;
      		int stepY;

      		int hit = 0; //was there a wall hit?
      		int side; //was a NS or a EW wall hit? NS = 1, EW = 0

			//calculate step and initial sideDist
			//deltaDist(x, y)는 물론 양수이고, sideDist(x, y)도 길이로써 비교하는 것이기 때문에 양수이다.
    		if (rayDirX < 0)
    		{
    			stepX = -1;
    			sideDistX = (posX - mapX) * deltaDistX;
    		}
    		else
    		{
    			stepX = 1;
    			sideDistX = (1 - (posX - mapX)) * deltaDistX;
    		}
    		if (rayDirY < 0)
    		{
    			stepY = -1;
    			sideDistY = (posY - mapY) * deltaDistY;
    		}
    		else
    		{
    			stepY = 1;
    			sideDistY = (1.0 - (posY - mapY)) * deltaDistY;
    		}

			/*위에서 계산에 필요한 변수들을 모두 구해주었다.
			** 벽에 부딪칠 때까지 광선을 뻗어나가주면 됨*/
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				//Check if ray has hit a wall
				if (worldMap[mapX][mapY] > 0) hit = 1;
			}

			/* 광선의 시작점에서부터 부딪친 벽까지의 거리계산 */
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if (side == 0)
				perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
				//fishDist = (mapX - posX) / rayDirX;
			else
				perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
				//fishDist = (mapY - posY) / rayDiry;
			//verticalDist = verticaldist_func();
			
			/*Draw the Wall*/
			//Calculate height of line to draw on screen
			int h =  screenHeight;
			int lineHeight = (int)(h / perpWallDist);
			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = h / 2 - lineHeight / 2;
			int drawEnd = h / 2 + lineHeight / 2;
			if( drawStart < 0)
				drawStart = 0;
			if( drawEnd >= h)
				drawEnd = h - 1;

			//벽의 색깔 설정
			ColorRGB color;
			switch(worldMap[mapX][mapY])
			{
				case 1:  color = RGB_Red;  break; //red
				case 2:  color = RGB_Green;  break; //green
				case 3:  color = RGB_Blue;   break; //blue
				case 4:  color = RGB_White;  break; //white
				default: color = RGB_Yellow; break; //yellow
			}
			//give x and y sides different brightness
			if (side == 1) {color = color / 2;}
			//draw the pixels of the stripe as a vertical line
			verLine(x, drawStart, drawEnd, color);
		}
		/*ray repeatation end*/
		//timing for input and FPS counter
		oldTime = time;
		time = getTicks(); //getTick 함수는 내가 설정하는 걸까, 아니면 시간차이가 계산되는 걸까?
		double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
		print(1.0 / frameTime); //FPS counter
		redraw();
		cls();

		//speed modifiers
		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
		
		readKeys();
    	//move forward if no wall in front of you
    	if (keyDown(SDLK_UP))
    	{
    	  if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
    	  if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    	}
    	//move backwards if no wall behind you
    	if (keyDown(SDLK_DOWN))
    	{
    	  if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
    	  if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    	}
    	//rotate to the right
    	if (keyDown(SDLK_RIGHT))
    	{
    	  //both camera direction and camera plane must be rotated
    	  double oldDirX = dirX;
    	  dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
    	  dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
    	  double oldPlaneX = planeX;
    	  planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
    	  planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    	}
    	//rotate to the left
    	if (keyDown(SDLK_LEFT))
    	{
    	  //both camera direction and camera plane must be rotated
    	  double oldDirX = dirX;
    	  dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
    	  dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
    	  double oldPlaneX = planeX;
    	  planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
    	  planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    	}
	}
	return (1);
}


double verticaldist_func(int mapX, double posX, int stepX, double rayDirX_one,
							int mapY, double posY, int stepY, double rayDirY_one, double fishDist)
{
	double vertical_slope[2];
	double x1; double y1;
	double c;
	double len;

	vertical_slope[X] = rayDirY_one * -1; //회전행렬
	vertical_slope[Y] = rayDirX_one * 1;
	x1 = posX + fishDist * rayDirX_one; // rayDir_one이 방향을 가지고 있으므로, +- 설정할 필요가 없다.
	y1 = posY + fishDist * rayDirY_one;

	c = vertical_slope[X] * (-1 * posX) + vertical_slope[Y] * (-1 * posY);
	len = abs(vertical_slope[X] * x1 + vertical_slope[Y] * y1 + c);
	return (len); 
}
