#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class QuickDemo {
public:
    void color_style_demo(Mat &image) {
        int colormap[] = {
                COLORMAP_AUTUMN,
                COLORMAP_BONE,
                COLORMAP_JET,
                COLORMAP_WINTER,
                COLORMAP_RAINBOW,
                COLORMAP_OCEAN,
                COLORMAP_SUMMER,
                COLORMAP_SPRING,
                COLORMAP_COOL,
                COLORMAP_PINK,
                COLORMAP_HOT,
                COLORMAP_PARULA,
                COLORMAP_MAGMA,
                COLORMAP_INFERNO,
                COLORMAP_PLASMA,
                COLORMAP_VIRIDIS,
                COLORMAP_CIVIDIS,
                COLORMAP_TWILIGHT,
                COLORMAP_TWILIGHT_SHIFTED
        };

        Mat dst;
        int index = 0;
        while (true) {
            int c = waitKey(500);
            if (c == 27) { // 退出
                break;
            }
            applyColorMap(image, dst, colormap[index%19]);
            index++;
            imshow("颜色风格", dst);
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
    qd.color_style_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
