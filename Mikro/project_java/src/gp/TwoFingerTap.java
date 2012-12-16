package gp;

public class TwoFingerTap implements IGesture{
	public final float x, y;
	
	public TwoFingerTap(float _x, float _y){
		x=_x; y=_y;
	}
	
	@Override
	public String getName(){
		return "Two Finger Tap";
	}

	@Override
	public String getDescription() {
		StringBuilder sb=new StringBuilder();
		sb.append("[");
		sb.append(x);
		sb.append(",");
		sb.append(y);
		sb.append("]");
		return sb.toString();
	}
}
