package dynamic_array;


public class Test {
	public static void main(String[] args) {
		
		MyArrayList<String> strs = new MyArrayList<String>();
		
		for (int i = 1; i <= 10; i++) {
			strs.add("元素" + i);
		}
		strs.add("元素" + 11);

		System.out.println(strs.get(10));
		
		System.out.println("要删除的元素为"+strs.remove(5));
		String[] arrays = strs.toArray(new String[strs.size()]);
		for (String string : arrays) {
			System.out.println(string);
		}
	
	}
}
