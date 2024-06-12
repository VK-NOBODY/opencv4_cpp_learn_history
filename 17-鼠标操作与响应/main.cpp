#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
Point sp(-1, -1);
Point ep(-1, -1);
Mat temp;

class QuickDemo {
public:
    static void on_draw(int event, int x, int y, int flags, void *userdata) {
        Mat image = *((Mat *) userdata);
        if (event == EVENT_LBUTTONDOWN) {
            sp.x = x;
            sp.y = y;
            std::cout << "start point:" << sp << std::endl;
        } else if (event == EVENT_LBUTTONUP) {
            ep.x = x;
            ep.y = y;
            int dx = ep.x - sp.x;
            int dy = ep.y - sp.y;
            if (dx > 0 && dy > 0) {
                Rect box(sp.x, sp.y, dx, dy);
                temp.copyTo(image);
                imshow("ROI区域", image(box));
                rectangle(image, box, Scalar(0, 0, 255), 2, 8, 0);
                imshow("鼠标绘制", image);
                // ready for next drawing
                sp.x = -1;
                sp.y = -1;
            }
        } else if (event == EVENT_MOUSEMOVE) {
            if (sp.x > 0 && sp.y > 0) {
                ep.x = x;
                ep.y = y;
                int dx = ep.x - sp.x;
                int dy = ep.y - sp.y;
                if (dx > 0 && dy > 0) {
                    Rect box(sp.x, sp.y, dx, dy);
                    temp.copyTo(image);
                    rectangle(image, box, Scalar(0, 0, 255), 2, 8, 0);
                    imshow("鼠标绘制", image);
                }
            }
        }
    }

    void mouse_drawing_demo(Mat &image) {
        namedWindow("鼠标绘制", WINDOW_AUTOSIZE);
        setMouseCallback("鼠标绘制", on_draw, (void *) (&image));
        imshow("鼠标绘制", image);
        temp = image.clone();
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
    qd.mouse_drawing_demo(src);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
