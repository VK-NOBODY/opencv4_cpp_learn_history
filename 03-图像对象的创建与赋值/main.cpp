#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void mat_creation_demo() {
        // Mat m1, m2;
        // m1 = image.clone();
        // image.copyTo(m2);

        // �����հ�ͼ��
        Mat m3 = Mat::zeros(Size(8, 8), CV_8UC3);
        m3 = Scalar(0, 0, 255);
        std::cout << "width: " << m3.cols << " height: " << m3.rows << " channels: "<<m3.channels()<< std::endl;
        // std::cout << m3 << std::endl;

        Mat m4;
        m3.copyTo(m4);
        m4 = Scalar(0, 255, 255);
        imshow("ͼ��", m3);
        imshow("ͼ��4", m4);
    }
};

int main(int argc, char **argv) {
    Mat src = imread("H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\xQc.jpg"); //  B, G, R
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }
    // namedWindow("���봰��", WINDOW_FREERATIO);
    imshow("���봰��", src);

    QuickDemo qd;
    qd.mat_creation_demo();

    waitKey(0);
    destroyAllWindows();
    return 0;
}
