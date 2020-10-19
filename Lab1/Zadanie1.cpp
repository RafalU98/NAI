#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main( int argc, char** argv ){
    bool capturing = true;
//VideoCapture cap( "szukaj_zielonego.webm" );
//VideoCapture cap( "rafalOkulary.webm" );// tu wlasny gif, niestety przyspieszony lecz nie wiem dlaczego
VideoCapture cap(0); 

if ( !cap.isOpened()){
    cerr << "Error przy Otwieraniu" << endl;
    return -1;
}
cout << "ROZMIARY Okna: " << cap.get( CAP_PROP_FRAME_WIDTH ) << "x" << cap.get( CAP_PROP_FRAME_HEIGHT ) << endl;
    do {
        Mat frame;
        Mat dst = frame;
        if ( cap.read( frame ) ) {
            flip ( frame,dst,1 );
            imshow("Okienko Prawie inteligentne",dst);
        } else {
            //stream finished
            capturing = false;
        }
        if( ( waitKey( 1000.0/60.0 )&0x0ff) == 27 ) {
            capturing = false;
        }
    } while( capturing );
return 0;
}
