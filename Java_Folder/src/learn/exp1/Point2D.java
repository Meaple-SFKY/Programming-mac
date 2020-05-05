/*-----------------  Point2D类  --------------*/

package src.learn.exp1;

public class Point2D {
    public int x;
    public int y;

    public Point2D() {
        x = 0;
        y = 0;
    }

    public void offset(int a, int b) {
        x += a;
        y += b;
    }
}