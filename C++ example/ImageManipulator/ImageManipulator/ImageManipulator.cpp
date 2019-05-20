#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	// 영상 읽기 project
	Mat image;

	// imread 함수 사용법 : imread(const String& filename, int flags = IMREAD_COLOR);
	image = imread("cat1.jpg", IMREAD_COLOR); // Read the file

	if (image.empty())                      // Check for invalid input
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}

	// namedWindow 함수 사용법 : namedWindow(const String& winname, int flags = WINDOW_AUTOSIZE);
	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	// WINDOW_AUTOSIZE : 사용자가 창 크기를 바꿀 수 없다.
	// WINDOW_NORMAL : 사용자가 창 크기를 바꿀 수 있다.

	// imshow 함수 사용법 : imshow(const String& winname, InputArray mat);
	imshow("Display window", image);                // Show our image inside it.

	waitKey(0); // Wait for a keystroke in the window


	// color image pixel access
	Mat src1;
	src1 = imread("cat1.jpg", IMREAD_COLOR);

	// 3 channel image with BGR color (type 8UC3)
	// the values can be stored in "int" or in "uchar". Here int is used.
	Vec3b intensity2 = src1.at<Vec3b>(10, 15);	// color image type : Vec3b, 이떄 10=y, 15=x
	int blue = intensity2.val[0];
	int green = intensity2.val[1];
	int red = intensity2.val[2];		// 순서가 B -> G -> R 순서로 되어 있다.
	cout << "Intensity = " << endl << " " << blue << " " << green << " " << red << endl << endl;

	// Modify the pixels of the BGR image
	for (int i = 100; i < src1.rows; i++)
	{
		for (int j = 100; j < src1.cols; j++)
		{
			src1.at<Vec3b>(i, j)[0] = 0;			// blue
			src1.at<Vec3b>(i, j)[1] = 200;			// green
			src1.at<Vec3b>(i, j)[2] = 0;			// red
		}
	}

}
