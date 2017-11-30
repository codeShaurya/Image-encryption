#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image;
    image = imread( "Image.jpg", 1 );
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Shubham@shaurya", WINDOW_AUTOSIZE );
    imshow("Shubham@shaurya", image);
    waitKey(0);

    return 0;
}