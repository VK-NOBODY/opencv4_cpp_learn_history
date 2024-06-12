#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void bitwise_demo(Mat &image) {
        Mat m1 = Mat::zeros(Size(256, 256), CV_8UC3);
        Mat m2 = Mat::zeros(Size(256, 256), CV_8UC3);
        rectangle(m1, Rect(100, 100, 80, 80), Scalar(255, 255, 0), -1, LINE_8, 0);
        rectangle(m2, Rect(150, 150, 80, 80), Scalar(0, 255, 255), -1, LINE_8, 0);
        imshow("m1", m1);
        imshow("m2", m2);
        Mat dst;
        bitwise_xor(m1, m2, dst);
        imshow("像素位操作", dst);
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
    qd.bitwise_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
