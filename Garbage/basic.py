import pygame as pg

pg.init();
win = pg.display.set_mode((500,500));

pg.display.set_caption("Some Game Called Ludo");

x = 200;
y = 200;
w = 40;
h = 40;
v = 5;

run = True;

while run:
    pg.time.delay(100);

    for event in pg.event.get():
        if event.type == pg.QUIT:
            run = False;
    pg.draw.rect( win , (255,0,255) , (x,y,h,w))
    pg.display.update()
