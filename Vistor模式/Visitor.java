package Vistor模式;

public interface Visitor {
	void visit(Member member);
	void visit(Vip vip);
}
