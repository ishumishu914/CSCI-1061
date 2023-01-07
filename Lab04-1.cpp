#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb/stb_image.h"
#include "stb/stb_image_resize.h"
#include "stb/stb_image_write.h"

using namespace std;

void create_a_random_pixel_location(int width, int height, int& r, int &c) 
{
    r = rand() % height;
    c = rand() % width;
}

// Image structure
struct MyImg 
{
    unsigned char* data;
    int width;
    int channels;
    int height;
    string filename;
};

void print_img_info(MyImg* img)
{
    cout << "width = " << img->width << "\n"
        << "height = " << img->height << "\n"
        << "channels = " << img->channels << endl;
}

void delete_img(MyImg** img)
{
    // Deletes img and sets it to NULL
    stbi_image_free(img);
    img = NULL;
}

// Image read/write
MyImg* load_jpeg_file(const string& filename) 
{
    // Returns a MyImg pointer containing image data.
    // If the file loading is unsuccessful, it returns a 0 
    MyImg* img = new MyImg;
    int width, height, channels;
    img->data = stbi_load("apple.jpg", &img->width, &img->height, &img->channels, 0); // desired number of channels = 0
    
    if (img == 0) 
    {
        cout << "Error loading image file" << endl;
    }
    print_img_info(img);
    return img;
}

void save_to_jpeg_file(const string& filename, MyImg* img)
{
    // Saves to a jpeg file
    stbi_write_jpg("apple-noisy.jpg", img->width, img->height, img->channels, img, 100 ); // quality = 100
}

//Setters
void set_pixel_red(MyImg* img, int r, int c, uint8_t val)
{
    // given a specific coordinate (row, col), move your pointer by how many bytes?
    // then assign that pointer with the value in your parameter
    
    unsigned char* p = img->data;
    for (int i=0; i<r; i++)
    {
        p += img->width * img->channels;
    } 
    for (int i=0; i<c; i++)
    {
        p += img->channels;
    }    
    *p = val;
}
void set_pixel_green(MyImg* img, int r, int c, uint8_t val)
{ 
    // given a specific coordinate (row, col), move your pointer by how many bytes?
    // then assign that pointer with the value in your parameter
    // but remember to take another step for green channel

    unsigned char* p = img->data;
    for (int i=0; i<r; i++)
    {
        p += img->width * img->channels;
    } 
    for (int i=0; i<c; i++)
    {
        p += img->channels;
    }  
    *(p + 1) = val;
}
void set_pixel_blue(MyImg* img, int r, int c, uint8_t val)
{    
    // given a specific coordinate (row, col), move your pointer by how many bytes?
    // then assign that pointer with the value in your parameter
    // but remember to take even moore step for green channel

    unsigned char* p = img->data;
    for (int i=0; i<r; i++)
    {
        p += img->width * img->channels;
    } 
    for (int i=0; i<c; i++)
    {
        p += img->channels;
    }  
    *(p + 2) = val;
}

// Getters
uint8_t get_pixel_red(MyImg* img, int r, int c)
{    
    // Similar to setter. Given specific coord (row, col), go to that position
    // return the value in that pixel 

    unsigned char* p = img->data;
    for (int i=0; i<r; i++)
    {
        p += img->width * img->channels;
    } 
    for (int i=0; i<c; i++)
    {
        p += img->channels;
    }    
    return *p;
}
uint8_t get_pixel_green(MyImg* img, int r, int c)
{    
    // same as red, but make sure to take another step for green channel

    unsigned char* p = img->data;
    for (int i=0; i<r; i++)
    {
        p += img->width * img->channels;
    } 
    for (int i=0; i<c; i++)
    {
        p += img->channels;
    }  
    return *(p + 1);
}
uint8_t get_pixel_blue(MyImg* img, int r, int c)
{    
    // same as red, but make sure to take another another step for blue channel

    unsigned char* p = img->data;
    for (int i=0; i<r; i++)
    {
        p += img->width * img->channels;
    } 
    for (int i=0; i<c; i++)
    {
        p += img->channels;
    }  
    return *(p + 2);
}

int main()
{
    MyImg* img = load_jpeg_file("apple.jpg");
    int total_pixels = img->width * img->height;
    int r, c;

    // task 1 - Set 20% of the total_pixels to black
    int blackPixNum = total_pixels * 0.2;
    srand(time(NULL));

    for (int i=0; i<blackPixNum; i++)
    {        
        create_a_random_pixel_location(img->width, img->height, r, c);

        set_pixel_red(img, r, c, 0);
        set_pixel_green(img, r, c, 0);
        set_pixel_blue(img, r, c, 0);
    }

    // Save results to apple-noisy.jpg taken from instruction
    stbi_write_jpg("apple-noisy.jpg", img->width, img->height, img->channels, img->data, 100 /* quality = 100 */);

    // Memory cleanup
    delete_img(&img);
 
    return 0;
}