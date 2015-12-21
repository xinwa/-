package Vistor模式;

public class Vip extends Customer{
	
	void doVip() {
		System.out.println("VIP服务");
	}
	
	@Override
	public void accept(Visitor visitor) {
		visitor.visit(this);
	}
}
