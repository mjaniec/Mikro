package com.example.mikro;

import com.example.mikro.R;

import gp.Delegator;
import gp.Flick;
import gp.Move;
import gp.Press;
import gp.Rotation;
import gp.Scroll;
import gp.Tap;
import gp.TwoFingerScroll;
import gp.TwoFingerTap;
import gp.Zoom;
import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.Toast;

public class MainActivity extends Activity implements OnTouchListener {

	static{
		try{ 
			System.loadLibrary("gp_Delegator");
		}catch(Exception e){
			e.printStackTrace();
			
		}
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
	
	@Override
	public boolean onTouch(View arg0, MotionEvent m) {
		
		Delegator d=Delegator.getInstance();
		d.recognize(m);
		 
		Flick flick=d.isFlick();
		Tap tap=d.isTap();
		Press press=d.isPress();
		Scroll scroll=d.isScroll();
		Move move=d.isMove();
		Rotation rotation=d.isRotation();
		TwoFingerTap twoFingerTap=d.isTwoFingerTap();
		Zoom zoom = d.isZoom();
		TwoFingerScroll twoFingerScroll=d.isTwoFingerScroll();
		if(tap!=null)Toast.makeText(getApplicationContext(), "Tap: "+tap.x+","+tap.y,Toast.LENGTH_SHORT).show();
		if(press!=null)Toast.makeText(getApplicationContext(), "Press: "+press.x+","+press.y,Toast.LENGTH_SHORT).show();
		if(scroll!=null)Toast.makeText(getApplicationContext(), "Scroll: "+scroll.direction,Toast.LENGTH_SHORT).show();
		if(flick!=null)Toast.makeText(getApplicationContext(), "Flick: "+flick.direction, Toast.LENGTH_SHORT).show();
		if(twoFingerScroll!=null)Toast.makeText(getApplicationContext(), "TwoFingerScroll: "+twoFingerScroll.direction, Toast.LENGTH_SHORT).show();
		//if(move!=null)Toast.makeText(getApplicationContext(), "Move: "+move.begx+ " " + move.begy + " " + move.x + " " + move.y, Toast.LENGTH_SHORT).show();
		if(zoom!=null)Toast.makeText(getApplicationContext(), "Zoom: "+zoom.direction+","+zoom.maginfication,Toast.LENGTH_SHORT).show(); 
		if(rotation!=null)Toast.makeText(getApplicationContext(), "Rotation: "+rotation.direction+", "+rotation.angle, Toast.LENGTH_SHORT).show();
		if(twoFingerTap!=null)Toast.makeText(getApplicationContext(), "TwoFingerTap: "+twoFingerTap.x+", "+twoFingerTap.y, Toast.LENGTH_SHORT).show();
	   
		return true;
	}
}
