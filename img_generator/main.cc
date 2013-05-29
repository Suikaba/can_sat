#include <iostream>
#include <fstream>
#include <memory>
#include <opencv/cv.hpp>
#include <opencv/highgui.h>

typedef unsigned int byte;

constexpr int img_width = 160;
constexpr int img_height = 120;
constexpr int img_size = img_width*img_height;

struct color_t {
    byte b, g, r;
};


int main(int argc, char* argv[])
{
    if( argc <= 1 ) return 0;

    color_t data[img_size]={};

    std::ifstream ifs( argv[1], std::ios::binary );
    if( !ifs ) return -1;
    ifs.read( reinterpret_cast<char*>( data ), sizeof( data ) );
    for( auto& x : data ) {
        x.b *= 16;
        x.g *= 16;
        x.r *= 16;
    }

    std::shared_ptr<IplImage> ipl(cvCreateImage(cvSize(img_width, img_height), IPL_DEPTH_8U, 3),
                                  []( IplImage* p ) { cvReleaseImage( &p ); });

    for(int y=0; y<ipl->height; ++y ) {
        for(int x=0; x<ipl->width; ++x) {
            const int dpos = (x * ipl->nChannels) + (ipl->widthStep * y);
            const int spos = x + (img_width * y);
            ipl->imageData[dpos] = data[spos].b;
            ipl->imageData[dpos+1] = data[spos+1].g;
            ipl->imageData[dpos+2] = data[spos+2].r;
        }
    }
    cvSaveImage("test.png", ipl.get());
}
