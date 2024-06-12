#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void key_demo(Mat &image) {
        Mat dst = Mat::zeros(image.size(), image.type());
        while (true) {
            int c = waitKey(100);
            if (c == 27) { // 退出
                break;
            }
            if (c == 49) { // Key #1
                std::cout << "you enter key # 1 "<< std::endl;
                cvtColor(image, dst, COLOR_BGR2GRAY);
            }
            if (c == 50) { // Key #2
                std::cout << "you enter key # 2 " << std::endl;
                cvtColor(image, dst, COLOR_BGR2HSV);
            }
            if (c == 51) { // Key #3
                std::cout << "you enter key # 3 " << std::endl;
                dst = Scalar(50, 50, 50);
                add(image, dst, dst);
            }
            imshow("键盘响应", dst);
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
    qd.key_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
