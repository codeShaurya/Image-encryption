#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

const int MAX=1e4+79;

int main()
{
	Mat image;
	double x[102];
    double u;  //u is the control parameter for chaotic map,also known as population rate

    image = imread( "Image.jpg", 1 );
    if ( !image.data )
    {
    	cout<<"No image data \n";
    	return -1;
    }
    //Applying Logistic map
    u=3.94;   //It is the condition for logistic map
    x[0]=0.4; //Base condition for logistic map
    for (int i = 1; i <= 100; ++i)
    	x[i]=u*x[i-1]*(1-x[i-1]);
    sort(x,x+100);

    // reading image pixel
    int i=1;
    int l;

    for(int r = 0; r < image.rows; ++r) {
    	for(int c = 0; c < image.cols; ++c) {
    		if(i>100){
    			i=1;
            }
            l=x[i]*MAX;
            l=l%255;
        // cout << "Pixel at position (x, y) : (" << c << ", " << r << ") =";
            image.at<Vec3b>(r,c)[0]=image.at<Vec3b>(r,c)[0]^l;
            image.at<Vec3b>(r,c)[1]=image.at<Vec3b>(r,c)[1]^l;
            image.at<Vec3b>(r,c)[2]=image.at<Vec3b>(r,c)[2]^l;
            i++;
        }
    }
    
    imwrite("encryptedImage.jpg",image);
    namedWindow("Shubham@shaurya", WINDOW_AUTOSIZE );
    imshow("Shubham@shaurya", image);
    waitKey(0);

    return 0;
}