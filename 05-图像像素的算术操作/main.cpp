#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void operators_demo(Mat &image) {
        Mat dst = Mat::zeros(image.size(), image.type());
        Mat m = Mat::zeros(image.size(), image.type());
        m = Scalar(5, 5, 5);

        // 加法
        /*
        int w = image.cols;
        int h = image.rows;
        int dims = image.channels();
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                Vec3b p1 = image.at<Vec3b>(row, col);
                Vec3b p2 = m.at<Vec3b>(row, col);
                dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
                dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
                dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
            }
        }
        */
        divide(image, m, dst);

        imshow("加法操作", dst);
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
    qd.operators_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
