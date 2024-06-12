#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void rotate_demo(Mat &image) {
        Mat dst, M;
        int w = image.cols;
        int h = image.rows;
        M = getRotationMatrix2D(Point2f(w / 2, h / 2), 45, 1.0);
        double cos = abs(M.at<double>(0, 0));
        double sin = abs(M.at<double>(0, 1));
        int nw = cos*w + sin*h;
        int nh = sin*w + cos*h;
        M.at<double>(0, 2) += (nw / 2 - w / 2);
        M.at<double>(1,2) += (nh / 2 - h / 2);
        warpAffine(image, dst, M, Size(nw, nh), INTER_LINEAR, 0, Scalar(255, 255, 0));
        imshow("旋转演示", dst);
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
    qd.rotate_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
