1. ## Getting started

   - Print squares, circles, triangles and hexagons on the screen by writing the pixels accordingly;
   - Try adding gradients, making rainbows, and get comfortable with using the rgb colors;
   - Try making textures by generating the image in loops.

2. ## Hooks

   - a key is pressed, it will print the key code in the terminal.
   - the mouse if moved, it will print the current position of that mouse in the terminal.
   - a mouse is pressed, it will print the angle at which it moved over the window to the terminal.
3. ## Event

   - `ESC` key is pressed, your window should close.
   - window is resized, you should print something in your terminal.
   - the red cross is clicked, your window should close.
   - you press a key longer than x seconds, you should print something in your terminal.
   - mouse enters the window, you should print `Hello!` in your terminal, when it leaves, you should print `Bye!`.

4. ## Loops

   - Render a moving rainbow that shifts through all colors (screen turns red, becomes green and then becomes blue, then starts all over again).
   - Create a circle that you can move accross your screen using your WASD keys.

5. ## Images

   - Import a cursor of your choice and allow it to roam within the window freely.
   - Import a texture and replicate it accross your entire window.

6. ## Sync

   Now that you have a faint idea of what MLX sync can do, grab your previous tiny circle-game that you made in [loops](https://harm-smits.github.io/42docs/libs/minilibx/loops.html) and add MLX sync to your rendering!  
   (page flipping, frame buffer가 발생할 때, 사용해야하는 것 같다...  
   https://42born2code.slack.com/archives/CMX2R5JSW/p1596962348311000. )