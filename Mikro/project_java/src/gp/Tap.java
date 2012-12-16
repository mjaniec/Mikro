package gp;

public class Tap implements IGesture{
	public final float x, y;
	
	public Tap(float _x, float _y){
		x=_x; y=_y;
	}
	@Override
	public String getName(){
		return "Tap";
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
