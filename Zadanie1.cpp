#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

int main( int argc, char** argv ){
    bool capturing = true;
cv::VideoCapture cap(0);
if ( !cap.isOpened()){
    std::cerr << "error while opening" << std::endl;
    return -1;
}
cout << "ROZMIARY KAMERY: " << cap.get( cv::CAP_PROP_FRAME_WIDTH ) << "x" << cap.get( cv::CAP_PROP_FRAME_HEIGHT ) << endl;
    do {
        cv::Mat frame;
        cv::Mat dst = frame;
        if ( cap.read( frame ) ) {
            cv::flip ( frame,dst,1 );
            cv::imshow("Not-yet smart window",dst);
        } else {
            //stream finished
            capturing = false;
        }
    } while( capturing );
return 0;
}