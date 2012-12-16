package gp;

public class Flick implements IGesture{
	public final float x,y;
	public final boolean direction;
	public Flick(float _x, float _y, boolean _direction){
		x=_x; y=_y; direction=_direction;
 	}
	
	@Override
	public String getName(){
		return "Flick";
	}
  
	@Override 
	public String getDescription() {
		StringBuilder sb=new StringBuilder();
		if(direction)
			sb.append("Right, ended at: [");
		else sb.append("Left, ended at: [");
		sb.append(x);
		sb.append(",");
		sb.append(y);
		sb.append("]");
		return sb.toString();
	}
	
}
