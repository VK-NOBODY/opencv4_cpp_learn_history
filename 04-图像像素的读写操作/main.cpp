#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void pixel_visit_demo(Mat &image) {
        int w = image.cols;
        int h = image.rows;
        int dims = image.channels();
        /*
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                if (dims == 1) { // »Ò¶ÈÍ¼Ïñ
                    int pv = image.at<uchar>(row, col);
                    image.at<uchar>(row, col) = 255 - pv;
                }
                if (dims == 3) { // ²ÊÉ«Í¼Ïñ
                    Vec3b bgr = image.at<Vec3b>(row, col);
                    image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
                    image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
                    image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
                }
            }
        }
        */

        for (int row = 0; row < h; row++) {
            uchar* current_row = image.ptr<uchar>(row);
            for (int col = 0; col < w; col++) {
                if (dims == 1) { // »Ò¶ÈÍ¼Ïñ
                    int pv = *current_row;
                    *current_row++ = 255 - pv;
                }
                if (dims == 3) { // ²ÊÉ«Í¼Ïñ
                    *current_row++ = 255 - *current_row;
                    *current_row++ = 255 - *current_row;
                    *current_row++ = 255 - *current_row;
                }
            }
        }
        imshow("ÏñËØ¶ÁÐ´ÑÝÊ¾", image);
    }
};

int main(int argc, char **argv) {
    Mat src = imread("H:\\Applications\\JetBrains\\JetBrains_Documents\\JetBrains_CLionProjects\\git_opencv_report\\xQc.jpg"); //  B, G, R
    if (src.empty()) {
        printf("could not load image....\n");
        return -1;
    }
    // namedWindow("ÊäÈë´°¿Ú", WINDOW_FREERATIO);
    imshow("ÊäÈë´°¿Ú", src);

    QuickDemo qd;
    qd.pixel_visit_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
