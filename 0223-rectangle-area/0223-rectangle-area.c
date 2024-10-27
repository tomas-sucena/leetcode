#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a > b) ? a : b)

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area1 = (ax2 - ax1) * (ay2 - ay1); // area of the 1st rectangle
    int area2 = (bx2 - bx1) * (by2 - by1); // area of the 2nd rectangle

    // compute the area of the intersection of the two rectangles
    int ix1 = MAX(ax1, bx1),
        ix2 = MIN(ax2, bx2),
        iy1 = MAX(ay1, by1),
        iy2 = MIN(ay2, by2);

    int intersection = (ix1 < ix2 && iy1 < iy2)
        ? (ix2 - ix1) * (iy2 - iy1) // the rectangles intersect
        : 0; // the rectangles do NOT intersect

    // compute the total area covered by the rectangles
    return area1 + area2 - intersection;
}