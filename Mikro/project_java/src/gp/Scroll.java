package gp;

public class Scroll implements IGesture {
	public final float x, y;
	public final boolean direction;
	Scroll(float _x, float _y, boolean _direction){
		x=_x; y=_y; direction=_direction;
	}
	
	@Override
	public String getName(){
		return "Scroll";
	}
	

	@Override
	public String getDescription() {
		StringBuilder sb=new StringBuilder();
		if(direction)
			sb.append("Down, ended at: [");
		else sb.append("Up, ended at: [");
		sb.append(x);
		sb.append(",");
		sb.append(y);
		sb.append("]");
		return sb.toString();
	}
}
