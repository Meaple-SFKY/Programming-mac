/*-----------------  Point3D.java  --------------*/

package src.learn.exp1;

public class Point3D extends Point2D {
    public int X;
    public int Y;
    public int Z;

    public Point3D(int x, int y, int z) {
        super();
        this.Z = z;
    }

    public Point3D(Point2D p, int z) {
        super();
        this.Z = z;
    }

    public void offset(int a, int b, int c) {
        this.X += a;
        this.Y += b;
        this.Z += c;
    }

    public static void main(String[] args) {
        Point2D p2d1 = new Point2D();
        Point2D p2d2 = new Point2D();
        p2d1.x = 1;
        p2d1.y = 2;
        p2d2.x = 3;
        p2d2.y = 4;
        double dist2d = Math.pow(Math.pow(p2d2.x - p2d1.x, 2) + Math.pow(p2d2.y - p2d1.y, 2), 0.5);
        System.out.println("The distance between point p2d1 and point p2d2 is: " + dist2d);

        Point3D p3d1 = new Point3D(p2d1, 1);
        Point3D p3d2 = new Point3D(4, 5, 6);
        double dist3d = Math.pow(Math.pow(p3d2.X - p3d1.X, 2) + Math.pow(p3d2.Y - p3d1.Y, 2) + Math.pow(p3d2.Z - p3d1.Z, 2), 1.0 / 3);
        System.out.println("The distance between point p3d1 and point p3d2 is: " + dist3d);
    }
}