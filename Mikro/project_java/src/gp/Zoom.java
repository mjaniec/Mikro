package gp;

public class Zoom implements IGesture {
	public final float maginfication;
	public final boolean direction;
	
	public Zoom(float _magnification, boolean _direction){
		maginfication=_magnification;
		direction=_direction;
	}	
	
	@Override
	public String getName(){
		return "Zoom";
	}
	
	@Override
	public String getDescription() {
		StringBuilder sb=new StringBuilder();
		if(direction)
			sb.append("In: ");
		else
			sb.append("Out: ");
		sb.append(maginfication);
		return sb.toString();
	}
}
