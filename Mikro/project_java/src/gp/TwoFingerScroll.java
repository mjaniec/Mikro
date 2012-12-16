package gp;

public class TwoFingerScroll implements IGesture {
	public final float x, y;
	public final boolean direction;
	TwoFingerScroll(float _x, float _y, boolean _direction){
		x=_x; y=_y; direction=_direction;
	}

	@Override
	public String getName(){
		return "2 Finger Scroll";
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
