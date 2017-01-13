#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\aruco.hpp>
#include <iostream>

using namespace cv;
using namespace std;
using namespace aruco;

int main( int argc, char** argv )
{
	Dictionary dictionary = getPredefinedDictionary(DICT_6X6_250);
	int MarkerSize = 100;
	vector<vector<Point2f>> corners;
	vector<int> ids;
	Mat image = imread("1.jpg");
	Mat retImage, marker0;
	drawMarker(getPredefinedDictionary(DICT_6X6_250), 0, MarkerSize, marker0, 1);
	image.copyTo(retImage);
	unsigned char value;
	for (int i = 0; i < marker0.rows; ++i)
		for (int j = 0; j < marker0.cols; ++j)
		{
			value = marker0.at<uchar>(i, j);
			Vec3b colorValue = Vec3b(value, value, value);
			retImage.at<Vec3b>(50 + i, 50 + j) = colorValue;
		}
    //image = imread(argv[1], IMREAD_COLOR); // Read the file
	detectMarkers(retImage, getPredefinedDictionary(DICT_6X6_250), corners, ids);
	drawDetectedMarkers(retImage, corners, ids);
	
    if(! image.data) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl ;
        return -1;
    }

    //namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
    imshow( "Display window", retImage); // Show our image inside it.

    waitKey(0); // Wait for a keystroke in the window
    return 0;
}