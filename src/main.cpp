#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[]) {
	Mat3b img = Mat3b::zeros(300, 300);
	imshow("img", img);
	waitKey();
    return 0;
}