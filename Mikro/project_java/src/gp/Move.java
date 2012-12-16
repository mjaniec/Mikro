package gp;

public class Move implements IGesture{
	public final float x, y;
	public final float prev_x, prev_y;
	public final float first_x, first_y;
	public Move(float _x, float _y, float _prev_x, float _prev_y,float _first_x, float  _first_y ){
		x=_x; y=_y;
		prev_x=_prev_x;
		prev_y=_prev_y;
		first_x=_first_x;
		first_y=_first_y;
	}
	
	@Override
	public String getName(){
		return "Move";
	}
	
	@Override
	public String getDescription(){
		StringBuilder sb=new StringBuilder();
		sb.append("[");
		sb.append(x);
		sb.append(",");
		sb.append(y);
		sb.append("] mv [");
		sb.append(x-prev_x);
		sb.append(",");
		sb.append(y-prev_y);
		sb.append("]:[");
		sb.append(x-first_x);
		sb.append(",");
		sb.append(y-first_y);
		sb.append("]");
		
		return sb.toString();
	}
	 
}
