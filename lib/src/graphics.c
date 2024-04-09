#include "../include/graphics.h"


inline pixel_t getPixelColor(u32_t x, u32_t y)
{
    return *((pixel_t*)FB_START + y*XRES + x);
}

inline void setPixelColor(u32_t x, u32_t y, pixel_t color)
{
    *((pixel_t*)FB_START + y*XRES + x) = color;
}

void drawLine(u32_t x1, u32_t y1, u32_t x2, u32_t y2, vga_m13_color_t color)
{
    // get line axis lengths
    i32_t len_x = x2 - x1;
    i32_t len_y = y2 - y1;

    // get abs versions of length
    u32_t abs_len_x = len_x & 0x7FFFFFFF;
    u32_t abs_len_y = len_y & 0x7FFFFFFF;

    float slope = 0.f;
    float x = 0.f;
    float y = 0.f;

    int current = 0;
    


    // if x slope is greater or equal to y slope (angle <= 45)
    if (abs_len_x >= abs_len_y) 
    {
        // get slope 
        slope = (float)len_y / (float)abs_len_x;


        // tf does this do???
        if (len_x >= 0)
        {
            x = x1;
            y = y1;
        }
        else
        {
            x = x2;
            y = y2;
        }

        for (current = 0 ; current <= len_x ; current++)
        {
            if (y > (float)((int)y + .5f)) // round y
            {
                setPixelColor((u32_t)x + current, (u32_t)y + 1, color);
            }
            else // do not round
            {
                setPixelColor((u32_t)x + current, (u32_t)y, color);
            }

            y += slope;
        }
    }
    else if (abs_len_x < abs_len_y)
    {
        slope = len_x / abs_len_y;

        if (len_y >= 0)
        {
            x = x1;
            y = y1;
        }
        else
        {
            x = x2;
            y = y2;
        }
    }
}

void drawRectObj(vga_m13_color_t color, rect_t rect)
{
    for (register u32_t a = 0 ; a < rect.w * rect.h ; a++)
    {
        setPixelColor(rect.x + (a % rect.w), rect.y + (a / rect.w), color);
    }
}

void drawRect(vga_m13_color_t color, i32_t x, i32_t y, i32_t w, i32_t h)
{
    for (register u32_t a = 0 ; a < w * h ; a++)
    {
        setPixelColor(x + (a % w), y + (a / w), color);
    }
}

void drawGraphic(graphic_t graphic, i32_t x, i32_t y)
{
    for (register int a = 0 ; a < graphic.width * graphic.height ; a++)
    {
        setPixelColor
                    ( 
                        x + (a % graphic.width), 
                        y + (a / graphic.width), 
                        graphic.data[a]
                    );
    }
}

void drawGraphicClipped(graphic_t graphic, i32_t x, i32_t y, rect_t clip)
{
    for (register u32_t a = 0 ; a < clip.w * clip.h ; a++)
    {
        setPixelColor
                    (
                        x + (a % clip.w),
                        y + (a / clip.w),
                        graphic.data[
                                        clip.x + // start at x offset of clipped section
                                        (a % clip.w) + // x iterator
                                        (clip.y * graphic.width) + // start at y offset of clipped section
                                        (a / clip.w) * graphic.width // y iterator 
                                    ]
                    );
    }
}

void clearScreen(u8_t color)
{
    for(u8_t* i = VGA_M13_FB_START ; i < VGA_M13_FB_START + XRES * YRES ; i++) 
        *i = color; 
}

void initRect(rect_t* rect, u32_t x, u32_t y, u32_t w, u32_t h)
{
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}

void initGraphic(graphic_t* graphic, u32_t w, u32_t h, pixel_t* data)
{
    graphic->width = w;
    graphic->height = h;
    graphic->data = data;
}