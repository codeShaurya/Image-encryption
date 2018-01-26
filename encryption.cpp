#include <stdio.h>
#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

const int MAX=1e4+79;
bool flag[513][513];

int main()
{
  Mat image;
  vector<pair<double,int >> x;
    double u=3.94,hold,temp;          //u is the control parameter for chaotic map,also known as population rate

    image = imread( "Image/sample_image_grey.jpg", 1 );
    if ( !image.data )
    {
      cout<<"No image data \n";
      return -1;
    }

    x.push_back({0.4,0});
    memset(flag ,false,sizeof(flag));

    for (int i = 1; i <= 511; ++i){
      temp=x[i-1].first;
      hold=u*temp*(1-temp);
      x.push_back({hold,i});
    }
    sort(x.begin(), x.end());

    int i=1;
    int l;

    imshow("Shubham@shaurya", image);
    waitKey(0);

    i=0;
    int  holds[4];
    for(int r = 0; r < image.rows; ++r) {
      for(int c = 0; c < image.cols; ++c) {
        if(i>511)
          i=0;
        int temps= x[i].second;

        holds[0]= image.at<Vec3b>(r,temps)[0];
        image.at<Vec3b>(r,temps)[0]=image.at<Vec3b>(r,c)[0];
        image.at<Vec3b>(r,c)[0]=holds[0];

        holds[1]= image.at<Vec3b>(r,temps)[1];
        image.at<Vec3b>(r,temps)[1]=image.at<Vec3b>(r,c)[1];
        image.at<Vec3b>(r,c)[1]=holds[1];


        holds[2]= image.at<Vec3b>(r,temps)[2];
        image.at<Vec3b>(r,temps)[2]=image.at<Vec3b>(r,c)[2];
        image.at<Vec3b>(r,c)[2]=holds[2];

        i++;
      }
    }

    for(int r = 0; r < image.rows; ++r) {
      for(int c = 0; c < image.cols; ++c) {
        if(i>100){
         i=1;
       }
       l=x[i].first*MAX;
       l=l%255;
       image.at<Vec3b>(r,c)[0]=image.at<Vec3b>(r,c)[0]^l;
       image.at<Vec3b>(r,c)[1]=image.at<Vec3b>(r,c)[1]^l;
       image.at<Vec3b>(r,c)[2]=image.at<Vec3b>(r,c)[2]^l;
       i++;
     }
   }


    imwrite("Image/encrypted_image.jpg",image);
    imshow("Shubham@shaurya", image);
    waitKey(0);

   i=1;
   for(int r = 0; r < image.rows; ++r) {
    for(int c = 0; c < image.cols; ++c) {
      if(i>100){
       i=1;
     }
     l=x[i].first*MAX;
     l=l%255;
     image.at<Vec3b>(r,c)[0]=image.at<Vec3b>(r,c)[0]^l;
     image.at<Vec3b>(r,c)[1]=image.at<Vec3b>(r,c)[1]^l;
     image.at<Vec3b>(r,c)[2]=image.at<Vec3b>(r,c)[2]^l;
     i++;
   }
 }

    i=511;
    for(int r = image.rows-1; r >= 0; --r) {
      for(int c = image.cols-1; c >= 0 ; --c) {
        if(i<0)
          i=511;
        int temps= x[i].second;

        holds[0]= image.at<Vec3b>(r,temps)[0];
        image.at<Vec3b>(r,temps)[0]=image.at<Vec3b>(r,c)[0];
        image.at<Vec3b>(r,c)[0]=holds[0];

        holds[1]= image.at<Vec3b>(r,temps)[1];
        image.at<Vec3b>(r,temps)[1]=image.at<Vec3b>(r,c)[1];
        image.at<Vec3b>(r,c)[1]=holds[1];


        holds[2]= image.at<Vec3b>(r,temps)[2];
        image.at<Vec3b>(r,temps)[2]=image.at<Vec3b>(r,c)[2];
        image.at<Vec3b>(r,c)[2]=holds[2];

        i--;
      }
    }

    namedWindow("Shubham@shaurya", WINDOW_AUTOSIZE );
    imshow("Shubham@shaurya", image);
    waitKey(0);

    return 0;
  }