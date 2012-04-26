//sg
package org.bvpgtug.chaos;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Notification;
import android.app.NotificationManager;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
public class SgRadioActivity extends Activity {
    /** Called when the activity is first created. */
    static ArrayAdapter<String> aa;
    static ArrayList<String> messages,acList;
	public int currNumMessages,prevNumMessages=0;
	String sourceURL;
	
	Button B;
	EditText tv3;
    public void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
    	setContentView(R.layout.main);
    	sourceURL="http://192.168.1.2/messageList1.xml";
    	ListView lv=(ListView)findViewById(R.id.msgLv);
       B=(Button)findViewById(R.id.refB);
		tv3=(EditText)findViewById(R.id.tv3);
		 messages=new ArrayList<String>();
	        acList=new ArrayList<String>();
	        aa=new ArrayAdapter<String>(this,R.layout.toastview,acList);
			lv.setAdapter(aa);
			
		B.setOnClickListener(new Button.OnClickListener()
		{
			@Override
			public void onClick(View v) {
			String surl=(String) tv3.getText().toString();
			sourceURL="http://"+surl+"/incoming.xml";
			Log.d("URL", sourceURL);
			B.setVisibility(View.GONE);
			tv3.setVisibility(View.GONE);
				
			Log.d("LOCATION", "IN onClick()");
			}
		});
		toCallAsynchronous();
         		}
	public boolean onCreateOptionsMenu(Menu m)
	{
		MenuItem m1=m.add(0,Menu.FIRST,Menu.NONE,R.string.ch_src);
		MenuItem m2=m.add(0,Menu.FIRST+1,Menu.NONE,R.string.ref_now);
		m1.setIcon(R.drawable.rss);
		m2.setIcon(R.drawable.refresh);
		return true;
	}
	@Override
	public boolean onOptionsItemSelected(MenuItem mi)
	{
		super.onOptionsItemSelected(mi);
		if(mi.getItemId()==Menu.FIRST)
		{
		B.setVisibility(View.VISIBLE);
		tv3.setVisibility(View.VISIBLE);
		return true;
		}
		else if(mi.getItemId()==Menu.FIRST+1)
		{
		new BWorker().execute();
		return true;
		}
		else
			return false;
		}
	public  class BWorker extends AsyncTask<Void,Void,Void>
	{
	 protected Void doInBackground(Void...params)
		{
			 messages.clear();
	    	try
	    	{
	    	URL u=new URL(sourceURL);
	    	URLConnection conn=u.openConnection();
	    	HttpURLConnection hconn=(HttpURLConnection)conn;
	    	InputStream incoming=hconn.getInputStream();
	    	DocumentBuilderFactory dbf=DocumentBuilderFactory.newInstance();
	    	DocumentBuilder db=dbf.newDocumentBuilder();
	    	Document msg=db.parse(incoming);
	    	Element e1=msg.getDocumentElement();
	    	NodeList n1=e1.getElementsByTagName("Message");
	    	if(n1!=null&&n1.getLength()>0)
	    	{
	    		
	    		Element counter=(Element) n1.item(0);
	    		Log.d("counter1:","COUNT");
	    		String cnt=counter.getElementsByTagName("Content").item(0).getFirstChild().getNodeValue();
	    		Log.d("counter:",cnt);
	    		currNumMessages=Integer.parseInt(cnt);
	    	   
	    	    		
	    		for(int i1=1;i1<n1.getLength();i1++)
	    	{
	    	Element msg1=(Element)n1.item(i1);
	    	print(msg1);
	    	}
	    	}
	    	Log.d("LOCATION","DO IN BACKGROUND");
	    	revList(messages);
	    	}
	    	catch(Exception e)
	    	{
	    		Log.d("ERROR",e.toString());
	    	}
			finally
			{
			}
			return null;
		}
		public void print(Element e2)
	    {
	    Element to=(Element)e2.getElementsByTagName("By").item(0);
	    Element content=(Element)e2.getElementsByTagName("Content").item(0);
	    String to1=to.getFirstChild().getNodeValue();
	    String msg1=content.getFirstChild().getNodeValue();
	    String res="Message: "+msg1+"Sender:"+to1+"";
	    messages.add(res);
	    }
		public void revList(ArrayList<String> m1)
		{
			acList.clear();
			int length=m1.size();
			
			for(int i=length-1;i>=1;i--) //first message contains info about number of messages
			{
				acList.add(m1.get(i));
			}
			
			}
			
		
		@Override
		public void onPostExecute(Void v)
		{
			
		if(prevNumMessages!=currNumMessages)
    	{
			prevNumMessages=currNumMessages;
			aa.notifyDataSetChanged();
			NotificationManager nm=(NotificationManager)getSystemService(Context.NOTIFICATION_SERVICE);
			Notification note=new Notification();
			Uri ru=RingtoneManager.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION);
			note.sound=ru;
			nm.notify(1,note);
			
    		AlertDialog.Builder ad=new AlertDialog.Builder(SgRadioActivity.this);
    		ad.setTitle("NEW MESSAGE!!!");
    		ad.setMessage("The Message List Has Been Updated!");
    		ad.setPositiveButton("Alright", new OnClickListener(){
    		
    			public void onClick(DialogInterface d,int arg)
    			{}
    		}
    		);
    		ad.show();
    		
    	}
    	
    	Log.d("LOCATION","ON POST EXECUTE");
		}
		
		}
	   public void toCallAsynchronous() {
		    TimerTask doAsynchronousTask;
		    final Handler handler = new Handler();
		    Timer timer = new Timer();


		            doAsynchronousTask = new TimerTask() {

		                @Override
		                public void run() {
		                    handler.post(new Runnable() {
		                        public void run() {

		                            try {
		                              BWorker performBackgroundTask = new BWorker();
		         performBackgroundTask.execute();
                   } catch (Exception e) {
	                            }

		                        }
		                    });

		                }

		            };
	
		            timer.schedule(doAsynchronousTask, 0,10000);
}
}
