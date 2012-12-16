package gp;

public class Press implements IGesture {
	public final float x,y;
	public Press(float _x, float _y){
		x=_x; y=_y;
	}
	
	@Override
	public String getName(){
		return "Press";
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
