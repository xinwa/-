package 台湾xd;

import java.util.Iterator;

public class IterableString implements Iterable<Character>{

	private String originString;
	
	public IterableString(String str){
		this.originString = str;
	}
	@Override
	public Iterator<Character> iterator() {
		// TODO Auto-generated method stub
		return new InnerIterator();
	}
	
	private class InnerIterator implements Iterator<Character>{

		private int index;
		@Override
		public boolean hasNext() {
			// TODO Auto-generated method stub
			return index < originString.length();
		}

		@Override
		public Character next() {
			// TODO Auto-generated method stub
			return  originString.charAt(index++);
		}

		@Override
		public void remove() {
			// TODO Auto-generated method stub
			originString = originString.substring(0, index)+originString.substring(index+1);
		}
		
	}
	public static void main(String[] args) {
		IterableString str = new IterableString("xinwa");
		//foreach(str.iterator());
		for (Character character : str) {
			System.out.println(character);
		}
	}
	
	public static void foreach(Iterator<Character> iterator){
		int i = 0;
		while(iterator.hasNext()){
			if(i == 2){
				iterator.remove();
			}
			System.out.println(iterator.next());
			i++;
		}
	}
}
