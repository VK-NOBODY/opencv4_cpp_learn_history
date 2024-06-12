#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void channels_demo(Mat &image) {
        std::vector<Mat> mv;
        split(image, mv);
        imshow("��ɫ", mv[0]);
        imshow("��ɫ", mv[1]);
        imshow("��ɫ", mv[2]);

        Mat dst;
        mv[0] = 0;
        // mv[1] = 0;
        merge(mv, dst);
        imshow("��ɫ", dst);

        int from_to[] = { 0, 2, 1,1, 2, 0 };
        mixChannels(&image, 1, &dst, 1, from_to, 3);
        imshow("ͨ�����", dst);
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
    qd.channels_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
