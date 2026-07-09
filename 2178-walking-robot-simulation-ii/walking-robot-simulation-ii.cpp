class Robot {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0} , {0, -1}};

    int idx;
    int currrow, currcol;
    int w, h;
    bool moved;

    Robot(int width, int height) {
        w = width;
        h = height;
        currrow = 0;
        currcol = 0;
        idx = 0;
        moved = false;
    }

    void step(int num) {
        if (w == 1 && h == 1) return;

        int perimeter = 2 * (w + h) - 4;
        num %= perimeter;

        if (num == 0 && moved)
            num = perimeter;

       moved = true;

        while (num--) {
            int nr = currrow + dir[idx][1];
            int nc = currcol + dir[idx][0];

            if (nr < 0 || nr >= h || nc < 0 || nc >= w) {
                idx = (idx + 1) % 4;
                nr = currrow + dir[idx][1];
                nc = currcol + dir[idx][0];
            }

            currrow = nr;
            currcol = nc;
        }
    }

    vector<int> getPos() {
        return {currcol, currrow};
    }

    string getDir() {
        if (!moved) return "East";

        if (idx == 0) return "East";
        if (idx == 1) return "North";
        if (idx == 2) return "West";
        return "South";
    }
};