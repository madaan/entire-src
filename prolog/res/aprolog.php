<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<!--Place meta tags here-->
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Amzi! inc. Adventure in Prolog tutorial</title>
<meta name="description" content="Tutorial explains Prolog concepts with text, diagrams and 
specialized diagrams for illustrating flow-of-control. Uses 
full program examples to lead you step-by-step 
through writing: an adventure game, an intelligent data-base, 
an expert system and an order entry program.">
<meta name="keywords" content="Prolog, Prolog language, Prolog tutorial,
Prolog programming, Prolog examples, free Prolog, Prolog interpreter, 
logic, logic programming, 
AI, artificial intelligence, rules, business rules, process rules, rule-based systems, 
expert systems,  
reasoning, inferencing, inference engines, intelligent software, 
sample code, source code, 
Amzi! Prolog, Amzi!, Amzi, Adventure in Prolog, Logic Explorer
">

<meta name="author" content="Amzi! inc." />

<!--Make sure this always points to the stylesheet-->
<link href="/main.css" rel="stylesheet" type="text/css" />
<link rel="shortcut icon" href="/favicon.ico" type="image/x-icon">
<link rel="icon" href="/favicon.ico" type="image/x-icon">
<script type="text/javascript">

  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-8213130-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
</head>

<body>
<div id="big_picture">
<!-- The top bar -->
<div style="background:#000000; padding: 0px; width:800px;">
  <div style="background:#000000; width:150px; height:125px; float:left;">
		<img src="/images/squirrel_125x140.jpg" width="140" height="125" />
  </div>
    <div style="background:#000000; padding: 0px; float:left; height:125px; width:610px;">
    	<div style="background:#000000; vertical-align:middle; height:60px; padding: 5px;">
        	<div style="float:left; background:#000000; padding-left:15px; vertical-align:middle; width:200px;">
            	<!-- <h1>Amzi! inc.</h1> -->
                <img src="/images/amzi_text.jpg" />
            </div>
        	<div style="float:right; background:#000000;">
				<form action="http://www.google.com/cse" id="cse-search-box">
				<div>
                	<input type="hidden" name="cx" value="009543582401049328519:y_b7qntti6m" />
                	<input type="hidden" name="ie" value="UTF-8" />
                	<input type="text" name="q" size="31" />
                	<input type="submit" name="sa" value="Search" />
				</div>
            	</form>
            	<script type="text/javascript"
					src="http://www.google.com/cse/brand?form=cse-search-box&lang=en"></script>
            </div>
			<div style="clear:both;"></div>
		</div>
        <div style="background:#000000; padding: 10px; width:580px; font-size:14px;">
            <table width="80%" border="1" align="center" cellpadding="4" cellspacing="0" bordercolor="#CC9933">
              <tr>
                <td align="center"><a class="black" href="/index.php">Home</a></td>
                <td align="center"><a class="black" href="/AmziNewsletter">Newsletters</a></td>
                <td align="center"><a class="black" href="/articles">Articles</a></td>
                <td align="center"><a class="black" href="/videos">Videos</a></td>
                <td align="center"><a class="black" href="/support/index.php">Support</a></td>
                <td align="center"><a class="black" href="/company/contact_form.php">Contact</a></td>
              </tr>
          </table>
      </div>
    </div>
    <div style="clear:both;"></div>
</div>


<div id="content">

    <!--Side Navigation-->
    <div id="leftMenu">
<p align="center"><a href="index.php"><b>Adventure in Prolog</b></a></p>
<hr />
<p><a href="advtop.php">Contents</a></p>
<p><a href="apreface.php">Preface</a></p>
<p><a href="aprolog.php">Prolog Tools</a></p>
<p><a href="a1start.php">1- Getting Started</a></p>
<p><a href="a2facts.php">2- Facts</a></p>
<p><a href="a3simple.php">3- Simple Queries</a></p>
<p><a href="a4comqry.php">4- Compound Queries</a></p>
<p><a href="a5rules.php">5- Rules</a></p>
<p><a href="a6arith.php">6- Arithmetic</a></p>
<p><a href="a7manage.php">7- Managing Data</a></p>
<p><a href="a8recurs.php">8- Recursion</a></p>
<p><a href="a9struct.php">9- Data Structures</a></p>
<p><a href="a10unif.php">10- Unification</a></p>
<p><a href="a11lists.php">11- Lists</a></p>
<p><a href="a12oper.php">12- Operators</a></p>
<p><a href="a13cut.php">13- Cut</a></p>
<p><a href="a14cntrl.php">14- Control Structures</a></p>
<p><a href="a15nlang.php">15- Natural Language</a></p>
<p><a href="appendix.php">Appendix</a></p>
<p><a href="advidx.php">Index</a></p>
<p>
<br />
<br />
<br />

<br />
<br />
<br />
</p>


</div>    <!--End Side Navigation-->

    <div id="beef">
    
        <!--Start content-->

        <div style="margin-right: 5px; float:right; width:430px">
        <p class="caption"><img src="/images/debugger_nanisrch.jpg" alt="Amzi! Prolog Source Code Debugger" />
        <br/>Amzi! Prolog Source Code Debugger</p>
        </div>

<div>

<H1 align="center">Prolog Tools</H1><hr />
<p>For either learning or deploying Prolog we recommend:</p>
<h3 align="center">
<a href="../AmziPrologLogicServer/index.php">Amzi! Prolog + Logic Server</a>
<br />
FREE (IDE only)
</h3>
<p>The Amzi! Prolog IDE, with it's source code debugger, is an excellent tool
for getting a solid understanding of Prolog's dynamic variable binding and built-in search.</p>



<P>The Amzi! Logic Server provides the tools for deploying Prolog with other development tools.</P>
<p>  The full Amzi! Prolog + Logic Server package is available on either:</P>
<ul>
<li>an individual basis or</li>
<li>an institutional site license.</li>
</ul>
<h3 align="center"><a href="/AmziPrologLogicServer/store.php">Download</a></h3>

</div>
<div style="clear:both"></div>
<div>

        <div style="margin-left: 5px; float:left; width:430px">
        <p class="caption">
        Amzi! Prolog IDE<br/><img src="/images/ide_nanisrch.jpg" alt="Amzi! Prolog IDE" /></p>
        </div>


<p>
<br />
<br />
<br />
</p>
<h3 align="center">Other resources for learning Prolog</h3>
<P>Checkout the numerous articles on Prolog:</P>
<h3 align="center"><a href="/articles/index.htm">Prolog Articles</a></h3>

<p>and the archives from the years when Amzi! was editor of the AI Expert magazine.  Many of the AI techniques are illustrated with Prolog code.</p>
<h3 align="center"><a href="http://www.ainewsletter.com">AI Newsletter</a></h3>
</div>



      <!--end content-->
    </div>
<div style="clear:both;"></div>
<hr />
<p class="copyright">Copyright © 1995-2010 Amzi! inc. All Rights Reserved.<br />
Amzi!, Logic Server, ARulesXL, KnowledgeWright, Adventure in Prolog, Building Expert Systems in Prolog, are trademarks of Amzi! inc.<br />
Flying squirrel photo Copyright © Joe McDonald</p>
<br/></div>  <!-- content container -->
</div>  <!-- big_picture -->

</body>
</html>
