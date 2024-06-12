#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void random_drawing() {
        Mat canvas = Mat::zeros(Size(512, 512), CV_8UC3);
        int w = canvas.cols;
        int h = canvas.rows;
        RNG rng(12345);
        while (true) {
            int c = waitKey(10);
            if (c == 27) { // 退出
                break;
            }
            int x1 = rng.uniform(0, w);
            int y1 = rng.uniform(0, h);
            int x2 = rng.uniform(0, w);
            int y2 = rng.uniform(0, h);
            int b = rng.uniform(0, 255);
            int g = rng.uniform(0, 255);
            int r = rng.uniform(0, 255);
            // canvas = Scalar(0, 0, 0);
            line(canvas, Point(x1, y1), Point(x2, y2), Scalar(b, g, r), 1, LINE_AA, 0);
            imshow("随机绘制演示", canvas);
        }
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
    qd.random_drawing();

    waitKey(0);
    destroyAllWindows();
    return 0;
}
