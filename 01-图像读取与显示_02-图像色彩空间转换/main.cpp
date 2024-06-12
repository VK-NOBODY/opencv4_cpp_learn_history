#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void colorSpace_Demo(Mat &image) {
        Mat gray, hsv;
        cvtColor(image, hsv, COLOR_BGR2HSV);
        // H 0 ~ 180, S, V
        cvtColor(image, gray, COLOR_BGR2GRAY);
        imshow("HSV", hsv);
        imshow("灰度", gray);
        // imwrite("D:/hsv.png", hsv);
        // imwrite("D:/gray.png", gray);
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
    qd.colorSpace_Demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
