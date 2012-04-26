<html>
<head>
<title>Compose Message</title>

<style>

label {
    width:195px;
    line-height:23px;
    padding-left:5px;
    margin:5px;
    border: 1px solid #FFFFFF;
    float:left;
    background-color:#FFFFFF;
    color:#781351;
}

textarea
{
color: #781351;
background: #FFCC66;
border: 2px solid #781351;
}

select
{
color: #781351;
background: #FFCC66;
border: 2px solid #781351;
}

 
fieldset
{
border: 2px solid #781351;
width: 30em;
}


legend
{
color: #781351;
background: #FFCC66;
border: 2px solid #781351;
padding: 2px 6px
}
</style>

<script>
         function validateForm()
	{
		var x=document.forms["message"]["message"].value;
		if (x==null || x=="")
  		{
  			alert("Please Enter A Message");
  			return false;
  			}
	}
</script>
</head>

<?php
//sg
//Time Extraction
$x=getdate();
if(($x[minutes]+30)>=60)
	$x[hours]=$x[hours]+5;
else
	$x[hours]=intval($x[hours]+5+(($x[minutes]+30)/60));
$x[minutes]=($x[minutes]+30)%60;
$mtime="$x[mday]-$x[mon]-$x[year] $x[hours]:$x[minutes]:$x[seconds]";


if(isset($_GET['posted']))
{
$msgs = simplexml_load_file("messageList1.xml");
$i=0;
$bi=0;
$ci=0;
$di=0;
$ei=0;
$fi=0;
$gi=0;
//read all entries
foreach($msgs->children() as $msg) //for all messages of the file
  {
foreach($msg->children() as $info) //extract the info
  {
	if($i%6==0)
		$serial[$bi++]=$info;
	elseif($i%6==1)
		$msgrec[$ci++]=$info;
	elseif($i%6==2)
		$from[$di++]=$info;
	elseif($i%6==3)
		$stime[$ei++]=$info;
	elseif($i%6==4)
		$content[$fi++]=$info;
	else
		$priority[$gi++]=$info;
	$i++;
  }
}

//delete the file
unlink("messageList1.xml");

//recreate it
$xmlf=fopen("messageList1.xml","w+") or die("ERROR");

//now write the new entries
$start="<Messages>\n";
$end="\n</Messages>\n";
$mstart="\n<Message>";
$mend="\n</Message>\n";
fwrite($xmlf,"<?xml version=\"1.0\"?>");
fwrite($xmlf,$start);

//print the messages

for($i=0;$i<$bi;$i++)
{
fwrite($xmlf,$mstart);
$ser="<SerialNumber>".$serial[$i]."</SerialNumber>\n";
$grp="<MessageReceiverGroupNumber>".$msgrec[$i]."</MessageReceiverGroupNumber>\n";
$bystr="<From>".$from[$i]."</From>\n";
$timestr="<Time>".$stime[$i]."</Time>\n";
$contentstr="<Content>\n".$content[$i]."\n</Content>\n";
$prio="<Priority>".$priority[$i]."</Priority>\n";
fwrite($xmlf,$ser);
fwrite($xmlf,$grp);
fwrite($xmlf,$bystr);
fwrite($xmlf,$timestr);
fwrite($xmlf,$contentstr);
fwrite($xmlf,$prio);
fwrite($xmlf,$mend);
}

//NOW WRITE THE CURRENT MESSAGE AT THE LAST
fwrite($xmlf,$mstart);
fwrite($xmlf,"<SerialNumber>".$bi."</SerialNumber>\n");
fwrite($xmlf,"<MessageReceiverGroupNumber>\n".$_GET['receivergroup']."</MessageReceiverGroupNumber>");
fwrite($xmlf,"<From>\n".$_GET['sender']."</From>");
fwrite($xmlf,"<Time>\n".$mtime."</Time>");
fwrite($xmlf,"<Content>\n".$_GET['messagea']."</Content>");
fwrite($xmlf,"<Priority>\n".$_GET['prioritynumber']."</Priority>");
fwrite($xmlf,$mend);
fwrite($xmlf,$end);
fclose($xmlf);
?>

<script >
alert("Message Broadcasted");
</script>


<body background="Background.jpg" bgcolor="#FFFFFF" bgproperties="fixed" > 

<center>
<fieldset>
<legend>COMPOSE MESSAGE</legend>

<form name="message.php" action="" onsubmit="return validateForm()" method="get" align="center">

<br>
<label><big> Sender </label>
<input type="text" id="group name" name="sender" />
<br><br><br>

<label><big> Receiver Group </label>
<select name="receivergroup">
<option value="2" selected="selected">All</option>
<option value="0">Faculty</option>
<option value="1">Students</option>
</select>
<br><br><br>

<label> Priority Number </label>
<select name="prioritynumber">
<option value="0" selected="selected">0</option>
<option value="1">1</option>
<option value="2">2</option>
<option value="3">3</option>
<option value="4">4</option>
<option value="5">5</option>
</select>
<br><br><br>

<label> Message </label>
<textarea name="messagea" rows="5" cols="30"></textarea>
<br><br><br>

<input type="image" src="image.gif" width="100" height="100" value="Submit" />

</form>
</fieldset>
</center>
</body>
</html>