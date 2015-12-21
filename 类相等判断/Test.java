package 类相等判断;

import java.util.HashSet;
import java.util.Set;

public class Test {
	public static void main(String[] args) {
		Point p1 = new Point(1,1);
		Point p2 = new Point(1,1){
			@Override
			public String toString() {
				// TODO Auto-generated method stub
				return super.toString();
			}
		};
		Point p3 = new Point3D(1, 1, 1);
		Set<Point> pSet = new HashSet<Point>();
		pSet.add(p1);
		System.out.println(pSet.contains(p1));
		System.out.println(pSet.contains(p2));
		System.out.println(p1.equals(p2));
		System.out.println(pSet.contains(p3));
	}
}
