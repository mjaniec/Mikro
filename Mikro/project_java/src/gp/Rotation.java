package gp;

public class Rotation implements IGesture {
	public final float angle;
	public final boolean direction;
	
	public Rotation(float _angle, boolean _direction){
		angle=_angle; direction=_direction;
	}
	
	@Override
	public String getName(){
		return "Rotation"; 
	} 
	
	@Override
	public String getDescription(){
		StringBuilder sb=new StringBuilder();
		if(direction)
			sb.append("Left: ");
		else sb.append("Right: ");
		sb.append(angle);
		sb.append(" deg.");
		return sb.toString();
	}
}

