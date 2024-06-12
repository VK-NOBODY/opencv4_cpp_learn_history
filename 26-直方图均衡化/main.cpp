#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void histogram_eq_demo(Mat &image) {
        Mat gray;
        cvtColor(image, gray, COLOR_BGR2GRAY);
        imshow("灰度图像", gray);
        Mat dst;
        equalizeHist(gray, dst);
        imshow("直方图均衡化演示", dst);
    }
};

int main(int argc, char **argv) {
    Mat src = imread(
            "H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\xQc.jpg"); //  B, G, R
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }
    // namedWindow("输入窗口", WINDOW_FREERATIO);
    imshow("输入窗口", src);

    QuickDemo qd;
    qd.histogram_eq_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
