package 类相等判断;

import java.util.HashSet;
import java.util.Set;

public class Point {
    protected  int x; //这里面被final修饰了，但是并没有发生初始化，待会继续考究
    protected  int y;
    
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    
    @Override
    public boolean equals(Object obj) {
    	// TODO Auto-generated method stub
    	if(obj instanceof Point){
    		Point p = (Point)obj;
    		//判断他们的类是否相等，类不相等时判定为不相等
//    		return this.getClass() == p.getClass() && this.x == p.x && this.y == p.y;
    		return p.canEquals(this) && this.x == p.x && this.y == p.y;
    	}
    	return false;
    }
    
    public boolean canEquals(Object that) {
        return that instanceof Point;
    }
    
    @Override
    public int hashCode() {
    	// TODO Auto-generated method stub
    	return 41*(41+x)+y;
    }
    public static void main(String[] args) {
		Point p1 = new Point(3,3);
		Point p2 = new Point(3,3);
		
		Set<Point> pSet = new HashSet<Point>();
		pSet.add(p1);
		
		System.out.println("set是否包含p1:"+pSet.contains(p1));
		p1.x = 2;
		System.out.println("set是否包含p1:"+pSet.contains(p1));
		System.out.println("set含有元素的个数为"+pSet.size());
		System.out.println(pSet.contains(p2));
		
	}
}
