package gp;
 
import android.view.MotionEvent; 
     
      
public class Delegator { 
	static private Delegator instance;
	static public Delegator getInstance(){
		if(instance==null)return instance=new Delegator();
		else return instance; 
	}               
	public int recognize(MotionEvent m){
		int pointers=m.getPointerCount();
		float pointersTable[]=new float[2000]; 
		for(int i=0; i<pointers; ++i){
			pointersTable[2*i+0]=m.getX(i); 
			pointersTable[2*i+1]=m.getY(i); 
		}   
		return recognize(m.getAction(),pointers,pointersTable,(int)(m.getEventTime()/10));
	}    
	protected native int recognize(int actionType, int size, float touches[], int time);
	public native Tap isTap(); 
	public native Press isPress();
	public native Flick isFlick();
	public native Move isMove();
	public native Rotation isRotation(); 
	public native Scroll isScroll(); 
	public native TwoFingerScroll isTwoFingerScroll();
	public native Zoom isZoom();
	public native TwoFingerTap isTwoFingerTap();
}
