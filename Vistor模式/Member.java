package Vistor模式;

public class Member extends Customer {
	
	void doMember() {
		System.out.println("会员服务");
	}
	
	@Override
	public void accept(Visitor visitor) {
		// TODO Auto-generated method stub
		visitor.visit(this);
	}
}
