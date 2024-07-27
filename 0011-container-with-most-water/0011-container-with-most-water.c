int maxArea(int* height, int heightSize) {
    int ans = -1;
    int left = 0, right = heightSize - 1;

    while (left < right) {
        int h, w = right - left;

        if (height[left] < height[right]) {
            h = height[left];
            ++left;
        }
        else {
            h = height[right];
            --right;
        }

        // calculate the area and verify if it is bigger
        // than the current best
        int area = h * w;

        if (area > ans) {
            ans = area;
        }
    }

    return ans;
}