package 类相等判断;

public class Point3D extends Point {

	private int z;

	public Point3D(int x, int y, int z) {
		super(x, y);
		this.z = z;
	}

	@Override
	public boolean equals(Object obj) {
		if (obj instanceof Point3D) {
			Point3D p = (Point3D) obj;
			return p.canEquals(this) && super.equals(p) && this.z == p.z;
		}
		return false;
	}

	@Override
	public boolean canEquals(Object that) {
		return that instanceof Point3D;
	}

	@Override
    public int hashCode() {
        return 41 * super.hashCode() + z;
    }
	
	public static void main(String[] args) {
		Point p1 = new Point(1, 1);
		Point p2 = new Point3D(1, 1, 1);
		Point p3 = new Point3D(1, 1, 2);

		System.out.println(p1.equals(p2));
		System.out.println(p2.equals(p1));
		System.out.println(p1.equals(p3));
		System.out.println(p2.equals(p3));
	}
}
