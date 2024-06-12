#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void inrange_demo(Mat &image) {
        Mat hsv;
        cvtColor(image, hsv, COLOR_BGR2HSV);
        Mat mask;
        inRange(hsv, Scalar(35, 43, 46), Scalar(77, 255, 255), mask);

        Mat redback = Mat::zeros(image.size(), image.type());
        redback = Scalar(40, 40, 200);
        bitwise_not(mask, mask);
        imshow("mask", mask);
        image.copyTo(redback, mask);
        imshow("roi区域提取", redback);
    }
};

int main(int argc, char **argv) {
    Mat src = imread("H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\xQc.jpg"); //  B, G, R
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }
    // namedWindow("输入窗口", WINDOW_FREERATIO);
    imshow("输入窗口", src);

    QuickDemo qd;
    qd.inrange_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
