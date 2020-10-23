#include <stdlib.h>
#include <stdio.h>
#include "ppm.h"

void drawHorLine (ppm *img, int startX, int endX, int y, int pixel);
void drawVertLine (ppm *img, int startY, int endY, int x, int pixel);

int main(void) {
  int redPixel = make_pixel(255U, 0U, 0U);
  int whitePixel = make_pixel(255U, 255U, 255U);

  ppm *img = make_image(500, 500, whitePixel);
  drawVertLine(img, 10, 150, 50, redPixel);
  drawHorLine(img, 10, 150, 50, redPixel);

  

  write_image(img, "img1.pnm");

  release_image(img);

  return 0;
}

void drawHorLine (ppm *img, int startX, int endX, int y, int pixel) {
  int x = 0;

  for (x = startX; x <= endX; x++)
  {
    set_pixel(img, x, y, pixel);
  }
}

void drawVertLine (ppm *img, int startY, int endY, int x, int pixel) {
  int y = 0;

  for (y = startY; y <= endY; y++)
  {
    set_pixel(img, x, y, pixel);
  }
}