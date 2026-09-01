class Solution {
public:
    double r, x, y;

    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint() {
        double xl = r * (2.0 * rand() / RAND_MAX - 1);
        double yl = r * (2.0 * rand() / RAND_MAX - 1);

        if (xl * xl + yl * yl <= r * r) {
            return {x + xl, y + yl};
        }

        return randPoint();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */