package Vistor模式;

public class VisitorImpl implements Visitor{

	@Override
	public void visit(Member member) {
		// TODO Auto-generated method stub
		member.doMember();
	}

	@Override
	public void visit(Vip vip) {
		// TODO Auto-generated method stub
		vip.doVip();
	}

}
