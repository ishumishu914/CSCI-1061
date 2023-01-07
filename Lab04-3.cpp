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
    img->data = stbi_load(filename.c_str(), &img->width, &img->height, &img->channels, 0); // desired number of channels = 0
    img->filename = filename;   

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
    stbi_write_jpg(filename.c_str(), img->width, img->height, img->channels, img->data, 100 ); // quality = 100
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

//vertical flip
void flip(MyImg* img, int dir)
{
  /*- Start with pointer on top left (usual starting point)
    - And another pointer on bottom left
    - run through the columns and switch the value 
      (memcpy or your getter/setter may be handy, or directly assign pointer values)
      http://www.cplusplus.com/reference/cstring/memcpy/
    - if you can't directly 'switch' 2 values, you'll have to do a swap like in bubble sort
    - then the top pointer goes down
    - and the bottom pointer goes up
    - repeat 
    (which means you may not need to scan all the pixels?)   
    1 2 3 4                  e f g h
    5 6 7 8   should become  a b c d
    a b c d                  5 6 7 8
    e f g h                  1 2 3 4
    in terms of this example:
     >> switch 1 with e
     >> switch 2 with f
     >> switch 3 with g
     >> switch 4 with h
     >> switch 5 with a
    and so on... */

    MyImg* img2 = new MyImg;
    img2->data = (unsigned char *)malloc(img->width * img->height * img->channels);
    img2->width = img->width;
    img2->height = img->height;
    img2->channels = img->channels;

    for (int i = 0; i < img->width; i++)
    {
        for (int j = 0, k = img->height-1; j<img->height, k>=0; j++, k--)
        {
            set_pixel_red(img2, j, i, get_pixel_red(img, k, i));
            set_pixel_green(img2, j, i, get_pixel_green(img, k, i));
            set_pixel_blue(img2, j, i, get_pixel_blue(img, k, i));                

        }            
    }
    *img = *img2;
}

int main()
{
    //task 3- flip image vertically
    MyImg* img = load_jpeg_file("apple.jpg");

    // Save results to apple-up-down.jpg taken from instruction
    flip(img, 0);
    save_to_jpeg_file("apple-up-down.jpg", img);

    // Memory cleanup
    delete_img(&img);
 
    return 0;
}