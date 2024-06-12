#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


class QuickDemo {
public:
    void flip_demo(Mat &image) {
        Mat dst;
        // flip(image, dst, 0); // ���·�ת
        // flip(image, dst, 1); // ���ҷ�ת
        flip(image, dst, -1); // 180����ת
        imshow("ͼ��ת", dst);
    }
};

int main(int argc, char **argv) {
    Mat src = imread(
            "H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\xQc.jpg"); //  B, G, R
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }
    // namedWindow("���봰��", WINDOW_FREERATIO);
    imshow("���봰��", src);

    QuickDemo qd;
    qd.flip_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
