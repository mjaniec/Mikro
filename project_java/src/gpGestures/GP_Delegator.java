package gpGestures;


public class GP_Delegator {
	static private GP_Delegator instance;
	static public GP_Delegator getInstance(){
		if(instance==null)return instance=new GP_Delegator();
		else return instance;
	}
	public native boolean recognize(int actionType, int size, float touches[][], int time);
	public native GP_Tap isTap();
	public native GP_Press isPress();
	public native GP_Flick isFlick();
	public native GP_Move isMove();
	public native GP_Rotate isRotate();
	public native GP_Scroll isScroll();
	public native GP_TwoFingerScroll isTwoFingerScroll();
	public native GP_Zoom isZoom();
}
