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
    stbi_write_jpg("apple-resized.jpg", img->width, img->height, img->channels, img->data, 100 ); // quality = 100
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

 /* - so we have original image A and the cropped canvas B
    - we want to transfer the relevant pixels from A to B
    for each row of the image:
    - where are we in terms of the current pointer location in original image A? 
      (how many rows down have we gotten? and also how many shifts away from the left - bc it's cropped)
    - where are we in image B? 
      (which row are we painting next)
      when we have identified our starting point in that row, then run through each of the pixels 
      in that row and copy the values from A to B 

    - allocate enough memory (in the form of a char array) to store the subregion
    - copy data one pixel at a time from the image to the subregion, using the getter and setter functions*/
MyImg* get_subregion(MyImg* src, int top, int left, int bottom, int right)
{  
    MyImg* img = new MyImg;
    int w = right-left;
    int h = bottom-top;    

    img->data = (unsigned char*)malloc(w*h*src->channels);
    img->channels = src->channels;
    img->width = w;
    img->height = h;

    for (int i=top-1; i<bottom; i++)
    {
        for (int j = left-1; j < right; j++)
        {
            set_pixel_red(img, i-top, j-left, get_pixel_red(src, i, j));
            set_pixel_green(img, i-top, j-left, get_pixel_green(src, i, j));
            set_pixel_blue(img, i-top, j-left, get_pixel_blue(src, i, j));
        }
    }
    return img;
}

int main()
{
    //task 2 - take a subregion of an image
    MyImg* img = load_jpeg_file("apple.jpg");
    int total_pixels = img->width * img->height;

    // Save results to apple-resized.jpg taken from instruction
    MyImg* img2 = get_subregion(img, 50, 5, 250, 250);
    save_to_jpeg_file("apple-resized.jpg", img2);

    // Memory cleanup
    delete_img(&img2);
 
    return 0;
}