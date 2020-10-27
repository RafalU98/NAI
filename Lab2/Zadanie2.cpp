#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    bool capturing = true;
    VideoCapture cap(0);
    VideoCapture cap2(1);

    if (!cap.isOpened()) {
        cerr << "Error przy Otwieraniu" << endl;
        return -1;
    }

    int width = 0;
    int height = 0;
    cout << endl;
    cout << "Enter the desired Window width" << endl;
    cin >> width;
    cout << "Enter the Window height" << endl;
    cin >> height;

    namedWindow("RangeHSV", WINDOW_AUTOSIZE);
    namedWindow("HSV", WINDOW_AUTOSIZE);


    int lRangeHue = 0;
    int uRangeHue = 0;

    int lRangeSat = 0;
    int uRangeSat = 0;

    int lRangeVal = 0;
    int uRangeVal = 0;

    createTrackbar("Lower Hue", "RangeHSV", &lRangeHue, 180);
    createTrackbar("Upper Hue", "RangeHSV", &uRangeHue, 180);

    createTrackbar("Lower Sat", "RangeHSV", &lRangeSat, 255); 
    createTrackbar("Upper Sat", "RangeHSV", &uRangeSat, 255);

    createTrackbar("Lower Val", "RangeHSV", &lRangeVal, 255);
    createTrackbar("Upper Val", "RangeHSV", &uRangeVal, 255);

    do {
        Mat frame, MyWindow, RangeHSV, HSV;
        cap >> frame;
        Mat dst = frame;

        if (cap.read(frame)) {
            if (width > 0 && height > 0) resize(frame, MyWindow, { width,height });
            else resize(frame, MyWindow, { 320,200 });
            putText(frame, "That is the right window ", { 300,30 }, FONT_HERSHEY_PLAIN, 1.0, { 255,4,4,4 });
            imshow("My Window", MyWindow);
            imshow("Window quite Intelignet", frame);
            GaussianBlur(MyWindow, dst, Size(5, 5), 0); 
            imshow("Gaussian Blur Active", dst);
        }

        else {
            capturing = false;
        }

        cvtColor(frame, RangeHSV, COLOR_BGR2HSV);
        cvtColor(frame, HSV, COLOR_BGR2HSV);

        inRange(RangeHSV, 
                Scalar(lRangeHue, lRangeSat, lRangeVal), 
                Scalar(uRangeHue, uRangeSat, uRangeVal),
                RangeHSV);

        imshow("MyRange", RangeHSV);
        imshow("HSV", HSV);


        if (waitKey(30) == 'x') {

            Mat frameROI;
            frameROI = frame.clone();
            auto r = selectROI("złapana klatka", frameROI);
            Mat roi = frameROI(r);
            imshow("ROI", roi);
            imwrite("MadePhoto.JPG", roi);
        }

        if ((waitKey(1000.0 / 60.0) & 0x0ff) == 27) {
            capturing = false;
        }

    } while (capturing);

    return 0;
}


