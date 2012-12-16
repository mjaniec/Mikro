package com.example.mikro;

import gp.Delegator;
import gp.IGesture;
import gp.Move;

import java.util.LinkedList;
import java.util.Queue;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.view.Window;
import android.widget.TextView;

public class MainActivity extends Activity implements OnTouchListener {

	static{
		try{ 
			System.loadLibrary("gp_Delegator");
		}catch(Exception e){
			e.printStackTrace();
			
		}
	}

	private Queue<IGesture> gestures=new LinkedList<IGesture>();
	
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.activity_main);
		((View)(findViewById( R.id.Screen))).setOnTouchListener(this);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	} 
	
	private void update(String name, String data){
		TextView name1,name2,name3;
		TextView data1,data2,data3;
		
		name1=(TextView)(findViewById(R.id.Out1Name));
		name2=(TextView)(findViewById(R.id.Out2Name));
		name3=(TextView)(findViewById(R.id.Out3Name));
		
		data1=(TextView)(findViewById(R.id.Out1Data));
		data2=(TextView)(findViewById(R.id.Out2Data));
		data3=(TextView)(findViewById(R.id.Out3Data));
		
		name3.setText(name2.getText());
		name2.setText(name1.getText());
		
		data3.setText(data2.getText());
		data2.setText(data1.getText());
		
		name1.setText(name);
		data1.setText(data);
	}
	
	private void update(){
		while(!gestures.isEmpty()){
			IGesture gesture=gestures.poll();
			if(gesture!=null)
				update(gesture.getName(),gesture.getDescription());
		}
	}
	
	private void draw(MotionEvent m){
		((View)(findViewById( R.id.View))).setOnTouchListener(this);
	}
	
	@Override
	public boolean onTouch(View arg0, MotionEvent m) {
		
		draw(m);
		
		
		Delegator d=Delegator.getInstance();
		d.recognize(m);
		 
		gestures.add(d.isFlick());
		gestures.add(d.isPress());
		gestures.add(d.isRotation());
		gestures.add(d.isScroll());
		gestures.add(d.isTap());
		gestures.add(d.isTwoFingerScroll());
		gestures.add(d.isTwoFingerTap());
		gestures.add(d.isZoom());

		//special handling for move
		Move move=d.isMove();
		if(move!=null){
			((TextView)(findViewById( R.id.MoveData))).setText(move.getDescription());
		}else{
			((TextView)(findViewById( R.id.MoveData))).setText("");
		}
		
		update();
	   
		return true;
	}
}
