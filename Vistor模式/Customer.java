package Vistor模式;

public class Customer implements Visitable{
	void doCustomer(){
		System.out.println("客户服务");
	}
	void pay(){
		System.out.println("结账");
	}
	
	@Override
	public void accept(Visitor visitor) {
		// TODO Auto-generated method stub
		
	}
}
