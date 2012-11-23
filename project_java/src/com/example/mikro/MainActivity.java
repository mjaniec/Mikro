package com.example.mikro;

import gpGestures.GP_Delegator;
import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.MotionEvent.PointerCoords;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.Toast;

public class MainActivity extends Activity implements OnTouchListener {

	static{
		System.loadLibrary("com_example_mikro_MainActivity");
	}
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		((View)(findViewById( R.id.View))).setOnTouchListener(this);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}

	native int GetGesture(int x, int y, int what);
	
	@Override
	public boolean onTouch(View arg0, MotionEvent m) {
		
		GP_Delegator delegator=GP_Delegator.getInstance();
		int pointers=m.getPointerCount();
		float pointersTable[][]=new float[pointers][2];
		for(int i=0; i<pointers; ++i){
			pointersTable[i][0]=m.getX(i);
			pointersTable[i][1]=m.getY(i);
		}
		delegator.recognize(m.getAction(),pointers,pointersTable,(int)(m.getDownTime()));
		
		if(delegator.isFlick()!=null)
			Toast.makeText(getApplicationContext(), "Flick",Toast.LENGTH_SHORT).show();
		if(delegator.isMove()!=null)
			Toast.makeText(getApplicationContext(), "Move",Toast.LENGTH_SHORT).show();
		if(delegator.isPress()!=null)
			Toast.makeText(getApplicationContext(), "Press",Toast.LENGTH_SHORT).show();
		if(delegator.isRotate()!=null)
			Toast.makeText(getApplicationContext(), "Rotate",Toast.LENGTH_SHORT).show();
		if(delegator.isScroll()!=null)
			Toast.makeText(getApplicationContext(), "Scroll",Toast.LENGTH_SHORT).show();
		if(delegator.isTap()!=null)
			Toast.makeText(getApplicationContext(), "Tap",Toast.LENGTH_SHORT).show();
		if(delegator.isTwoFingerScroll()!=null)
			Toast.makeText(getApplicationContext(), "TwoFingerScroll",Toast.LENGTH_SHORT).show();
		if(delegator.isZoom()!=null)
			Toast.makeText(getApplicationContext(), "Zoom",Toast.LENGTH_SHORT).show();
	   
		return true;
	}
}
