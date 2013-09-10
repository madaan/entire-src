<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html><head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>ERROR: The requested URL could not be retrieved</title>
<style type="text/css"><!-- 
 /*
 Stylesheet for Squid Error pages
 Adapted from design by Free CSS Templates
 http://www.freecsstemplates.org
 Released for free under a Creative Commons Attribution 2.5 License
*/

/* Page basics */
* {
	font-family: verdana, sans-serif;
}

html body {
	margin: 0;
	padding: 0;
	background: #efefef;
	font-size: 12px;
	color: #1e1e1e;
}

/* Page displayed title area */
#titles {
	margin-left: 5px;
	padding: 10px;
	padding-left: 150px;
	background: url('http://docs.iitb.ac.in/iitb_logo.jpg') no-repeat left;
}

/* initial title */
#titles h1 {
	color: #000000;
}
#titles h2 {
	color: #000000;
}

/* special event: FTP success page titles */
#titles ftpsuccess {
	background-color:#00ff00;
	width:100%;
}

/* Page displayed body content area */
#content {
	padding: 10px;
	background: #ffffff;
}

/* General text */
p {
}

/* error brief description */
#error p {
}

/* some data which may have caused the problem */
#data {
}

/* the error message received from the system or other software */
#sysmsg {
}

pre {
    font-family:sans-serif;
}

/* special event: FTP / Gopher directory listing */
#dirlisting tr.entry td.icon,td.filename,td.size,td.date {
    border-bottom: groove;
}
#dirlisting td.size {
    width: 50px;
    text-align: right;
    padding-right: 5px;
}

/* horizontal lines */
hr {
	margin: 0;
}

/* page displayed footer area */
#footer {
	font-size: 9px;
	padding-left: 10px;
}


body
:lang(fa) { direction: rtl; font-size: 100%; font-family: Tahoma, Roya, sans-serif; float: right; }
:lang(he) { direction: rtl; float: right; }
 --></style>
</head><body id=ERR_DNS_FAIL>
<div id="titles">
<h1>ERROR</h1>
<h2>The requested URL could not be retrieved</h2>
</div>
<hr>

<div id="content">
<p>The following error was encountered while trying to retrieve the URL: <a href="http://lib/plugins/indexmenu/cms/extensions/e.js">http://lib/plugins/indexmenu/cms/extensions/e.js</a></p>

<blockquote id="error">
<p><b>Unable to determine IP address from host name <q>lib</q></b></p>
</blockquote>

<p>The DNS server returned:</p>
<blockquote id="data">
<pre>Name Error: The domain name does not exist.</pre>
</blockquote>

<p>This means that the cache was not able to resolve the hostname presented in the URL. Check if the address is correct.</p>

<p>Your cache administrator is <a href="mailto:webmaster?subject=CacheErrorInfo%20-%20ERR_DNS_FAIL&amp;body=CacheHost%3A%20netmon.iitb.ac.in%0D%0AErrPage%3A%20ERR_DNS_FAIL%0D%0AErr%3A%20%5Bnone%5D%0D%0ADNS%20ErrMsg%3A%20Name%20Error%3A%20The%20domain%20name%20does%20not%20exist.%0D%0ATimeStamp%3A%20Fri,%2006%20Sep%202013%2017%3A47%3A24%20GMT%0D%0A%0D%0AClientIP%3A%2010.5.70.43%0D%0AServerIP%3A%20lib%0D%0A%0D%0AHTTP%20Request%3A%0D%0AGET%20%2Fplugins%2Findexmenu%2Fcms%2Fextensions%2Fe.js%20HTTP%2F1.1%0AHost%3A%20lib%0D%0AProxy-Connection%3A%20keep-alive%0D%0AProxy-Authorization%3A%20Basic%20MTMzMDUwMDA0OnNnXjEyMzQ1NmFtYW4%3D%0D%0AUser-Agent%3A%20Mozilla%2F5.0%20(X11%3B%20Linux%20i686)%20AppleWebKit%2F537.11%20(KHTML,%20like%20Gecko)%20Chrome%2F23.0.1271.97%20Safari%2F537.11%0D%0AAccept%3A%20*%2F*%0D%0AReferer%3A%20http%3A%2F%2Fwiki.bash-hackers.org%2Fhowto%2Fgetopts_tutorial%0D%0AAccept-Encoding%3A%20gzip,deflate,sdch%0D%0AAccept-Language%3A%20en-US,en%3Bq%3D0.8%0D%0AAccept-Charset%3A%20ISO-8859-1,utf-8%3Bq%3D0.7,*%3Bq%3D0.3%0D%0A%0D%0A%0D%0A">webmaster</a>.</p>
<br>
</div>

<hr>
<div id="footer">
<p>Generated Fri, 06 Sep 2013 17:47:24 GMT by netmon.iitb.ac.in (squid/3.1.14)</p>
<!-- ERR_DNS_FAIL -->
</div>
</body></html>
