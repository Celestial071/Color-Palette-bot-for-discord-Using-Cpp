#include <opencv2/opencv.hpp>
#include <map>
#include <iostream>

#define SIZE(x) sizeof(x)/sizeof(x[0]) 

typedef struct{
    unsigned int base;
    unsigned int cbase;
}palatte;

enum PopularColors {
    RED = 0xFF0000,
    GREEN = 0x00FF00,
    BLUE = 0x0000FF,
    YELLOW = 0xFFFF00,
    CYAN = 0x00FFFF,
    MAGENTA = 0xFF00FF,
    ORANGE = 0xFFA500,
    PURPLE = 0x800080,
    PINK = 0xFFC0CB,
    BROWN = 0xA52A2A
};

std::map<int, PopularColors> colorMap = {
    {0, RED},
    {1, GREEN},
    {2, BLUE},
    {3, YELLOW},
    {4, CYAN},
    {5, MAGENTA},
    {6, ORANGE},
    {7, PURPLE},
    {8, PINK},
    {9, BROWN}
};

bool inc_dec(){
    return (rand() % 2 == 0)?1:-1;
}

void create_palatte(palatte *current, size_t size){
    //setting base color
    current->base = colorMap[rand() % 10];
    current->cbase = 0xffffff - current->base;
    uint base = current->base;
    uint b = base;
    bool operation = inc_dec();
    current++;
    //take a random but small fluctuation to make the palatte look different
    uint jump_size = rand() % 3000+ 5000;
    for(size_t i=0; i<size-1; i++){
        if(b+jump_size * size > 0xffffff){
            operation = -1;
        }else if(b - jump_size * size < 0x000000){
            operation = +1;
        }
        current->base = base + (operation == 1?jump_size:-jump_size);
        current->cbase = 0xffffff - current->base;
        base = current->base;
        current++; 
    }
}

int main(){
    palatte color[4];
    srand(time(NULL));
    create_palatte(color, SIZE(color));
    for(int i=0; i<SIZE(color); i++){
        printf("base = %#6X && complimentary = %#6X\n", (uint)color[i].base, (uint)color[i].cbase);
    }

    // Create an image
    int width = 600, height = 100;
    cv::Mat img(height, width, CV_8UC3);

    // Draw each color as a rectangle in the image
    for (int i = 0; i < SIZE(color); ++i) {
        cv::rectangle(img, cv::Rect(i * width / (2*SIZE(color)), 0, width / (2*SIZE(color)), height), cv::Scalar((color[i].base & 0xFF), (color[i].base >> 8 & 0xFF), (color[i].base >> 16 & 0xFF)), -1);
        cv::rectangle(img, cv::Rect((i+SIZE(color)) * width / (2*SIZE(color)), 0, width / (2*SIZE(color)), height), cv::Scalar((color[i].cbase & 0xFF), (color[i].cbase >> 8 & 0xFF), (color[i].cbase >> 16 & 0xFF)), -1);
    }

    // Save the image
    cv::imwrite("./colorpalatte/color_palette.png", img);

    return 0;
}
