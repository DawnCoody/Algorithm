/**
 * 输入 3 个数值，判断以它们为边长是否能构成三角形。如果能构成，则判断属于哪种特殊三角形：等边、等腰或直角
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, c, flag;
    cout << "请输入三个边长：" << endl;
    cin >> a >> b >> c;
    if (a >= b + c || b >= a + c || c >= a + b) cout << "don't form a triangle" << endl;
    else {
        // 使用 flag 为了防止重复输入，比如：输出是直角三角形，就不要输出是三角形了
        flag = 0;
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) {
            flag = 1;
            cout << "form a right-angle triangle" << endl;
        } else if (a == b && b == c) {
            flag = 1;
            cout << "form a equilateral triangle" << endl;
        } else if (a == b or b == c or c == a) {
            flag = 1;
            cout << "form a equal haunch triangel" << endl;
        }
        if (flag == 0) {
            cout << "form a triangle" << endl;
        }
    }
    return 0;
}