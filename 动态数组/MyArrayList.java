package dynamic_array;

import java.util.Arrays;

public class MyArrayList<E>{
	
	private Object[] elementData;
	/**数组中元素的总数**/
	private int elementCount;
	/**需要扩展数组的增量**/
	private int capacityIncrement;
	/**默认的使数组长度为10**/
	private static int initElementCapacity = 10;
	
	public MyArrayList(){
		this(initElementCapacity);
	}
	
	public MyArrayList(int initCapacity){
		this(initCapacity,0);
	}
	
	public MyArrayList(int initCapacity,int increment) {
		if(initCapacity < 0)
			throw new IllegalArgumentException("初始化数组的长度不能小于等于0");
		
		elementData = new Object[initCapacity];
		this.capacityIncrement = increment;
	}
	
	public boolean add(E e){
		ensureCapacity();
		elementData[elementCount++] = e;
		return true;
	}
	
	public E remove(int position){
		if(position > elementCount)
			throw new ArrayIndexOutOfBoundsException(position);
		//如果删除的是最后一个元素的话，只需要将elementCount减一
		//然后将最后一个置为空，如果删除其他元素则需要重新生成一个数组
		//要移动的数组元素
		int numMove = elementCount -1 - position;
		E e = elementData(position);
		if(numMove > 0){
			System.arraycopy(elementData, position+1, elementData, position, numMove);
		}
		//这里通过让gc来回收用不到的空间
		elementData[elementCount--] = null;
		return e;
	}
	
	public E elementData(int position){
		return (E) elementData[position];
	}
	
	public boolean remove(Object o){
		return true;
	}
	
	private void ensureCapacity(){
		if(elementCount == elementData.length){
			inCreaseCapacity();
		}
	}
	
	private void inCreaseCapacity(){
		int oldLength = elementData.length;
		capacityIncrement =  capacityIncrement > 0 ? capacityIncrement : oldLength; 
		int newLength = capacityIncrement + elementData.length;
		elementData = Arrays.copyOf(elementData, newLength, Object[].class);
	}
	
	
	public E get(int position){
		return (E) elementData[position];
	}
	
	/**把集合转变为list,还不能直接返回集合中的数组，这样的话，如果在外边修改了返回的
	 * 数组会造成集合中的数组也会修改,故需要重新生成一个数组。
	 * 
	 * Arrays.copyOf多用于整体的对数组操作
	 * System.arraycopy 可以更加具体的对要复制的数组进行操作
	 * **/
	public <E> E[] toArray(E[] a){
		if(a.length < elementCount){
			return (E[]) Arrays.copyOf(elementData, a.length);
		}
		System.arraycopy(elementData, 0, a, 0, elementCount);

		//去掉多余开辟的空间
        if (a.length > elementCount)
            a[elementCount] = null;

        return a;
	}
	
	public int size(){
		return elementCount;
	}
	public int getElementCount() {
		return elementCount;
	}

	public void setElementCount(int elementCount) {
		this.elementCount = elementCount;
	}

	public int getCapacityIncrement() {
		return capacityIncrement;
	}

	public void setCapacityIncrement(int capacityIncrement) {
		this.capacityIncrement = capacityIncrement;
	}
	
}
