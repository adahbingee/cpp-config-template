#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[]) {
    Mat1b img = Mat1b::zeros(300, 300);
    imwrite("img.png", img + 50);
    return 0;
}