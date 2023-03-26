
#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;
struct coords {
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    float x4;
    float y4;
};
void drawFigure(struct coords* figure) {
    line(figure->x1, figure->y1, figure->x2, figure->y2);
    line(figure->x2, figure->y2, figure->x3, figure->y3);
    line(figure->x3, figure->y3, figure->x4, figure->y4);
    line(figure->x4, figure->y4, figure->x1, figure->y1);
}
void rotate(struct coords* figure, int angle) {
    float ox = (figure->x1 + figure->x2 + figure->x3 + figure->x4) / 4;
    float oy = (figure->y1 + figure->y2 + figure->y3 + figure->y4) / 4;
    float s = sin(angle*3.14/180);
    float c = cos(angle*3.14/180);
    float x = 0;
    float y = 0;
    x = figure->x1;
    y = figure->y1;
    figure->x1 = (x - ox) * c - (y - oy) * s + ox;
    figure->y1 = (x - ox) * s + (y - oy) * c + oy;
    x = figure->x2;
    y = figure->y2;
    figure->x2 = (x - ox) * c - (y - oy) * s + ox;
    figure->y2 = (x - ox) * s + (y - oy) * c + oy;
    x = figure->x3;
    y = figure->y3;
    figure->x3 = (x - ox) * c - (y - oy) * s + ox;
    figure->y3 = (x - ox) * s + (y - oy) * c + oy;
    x = figure->x4;
    y = figure->y4;
    figure->x4 = (x - ox) * c - (y - oy) * s + ox;
    figure->y4 = (x - ox) * s + (y - oy) * c + oy;
}
void scale(struct coords* figure, float coef) {
    int ox = (figure->x1 + figure->x2 + figure->x3 + figure->x4) / 4;
    int oy = (figure->y1 + figure->y2 + figure->y3 + figure->y4) / 4;
    figure->x1 = (figure->x1 - ox) * coef + ox;
    figure->y1 = (figure->y1 - oy) * coef + oy;
    figure->x2 = (figure->x2 - ox) * coef + ox;
    figure->y2 = (figure->y2 - oy) * coef + oy;
    figure->x3 = (figure->x3 - ox) * coef + ox;
    figure->y3 = (figure->y3 - oy) * coef + oy;
    figure->x4 = (figure->x4 - ox) * coef + ox;
    figure->y4 = (figure->y4 - oy) * coef + oy;
}
void shift(struct coords* figure, float dx, float dy) {
    figure->x1 = figure->x1 + dx;
    figure->y1 = figure->y1 + dy;
    figure->x2 = figure->x2 + dx;
    figure->y2 = figure->y2 + dy;
    figure->x3 = figure->x3 + dx;
    figure->y3 = figure->y3 + dy;
    figure->x4 = figure->x4 + dx;
    figure->y4 = figure->y4 + dy;
}
int main()
{

    struct coords figure = { 150, 150, 300, 150, 400, 300, 100, 300 };
    initwindow(900, 500);
    outtext(_strdup("Стрелки - перемещение; R - поворот; I - Увеличить размер; O - Уменьшить размер; 0 - Выход."));
    drawFigure(&figure);
    int c;
    do {
        c = (char)getch();
        clearviewport();
        outtext(_strdup("Стрелки - перемещение; R - поворот; I - Увеличить размер; O - Уменьшить размер; 0 - Выход."));
        switch (c) {
        case (KEY_UP):
            shift(&figure, 0, -2);
            break;
        case (KEY_DOWN):
            shift(&figure, 0, 2);
            break;
        case (KEY_LEFT):
            shift(&figure, -2, 0);
            break;
        case (KEY_RIGHT):
            shift(&figure, 2, 0);
            break;
        case 'i':
            scale(&figure, 1.05);
            break;
        case 'o':
            scale(&figure, 0.95);
            break;
        case 'r':
            rotate(&figure, 10);
            break;

        }
        drawFigure(&figure);
    } while (c != '0');
    
}


