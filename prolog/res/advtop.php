<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<!--Place meta tags here-->
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>Adventure in Prolog Tutorial
</title>
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

<H1 align="center">Adventure in Prolog</H1>

<HR>

<H2>Contents</H2>
<div style="margin-left:20px">
<TABLE "BORDER=0 CELLSPACING=0 CELLPADDING=0 >
<TR VALIGN=TOP>

<TD VALIGN=TOP>
      <DL> 
        <DT><A HREF="apreface.php"> Preface</A></DT>
        <DD> </DD>
        <DT>
          <P><A HREF="aprolog.php"> Prolog Tools</A>
        </DT>
        <DT> 
          <P><A HREF="a1start.php">1 Getting Started</A>
        </DT>
        <DD><A HREF="a1start.php#JumpingIn">Jumping In</A></DD>
        <DD><A HREF="a1start.php#LogicProgramming">Logic Programming</A></DD>
        <DD><A HREF="a1start.php#Jargon">Jargon</A></DD>
        <DT>
          <P><A HREF="a2facts.php"> 2 Facts</A>
        </DT>
        <DD><A HREF="a2facts.php#NaniSearch">Nani Search</A></DD>
        <DD><A HREF="a2facts.php#Exercises">Exercises</A></DD>
        <DT>
          <P><A HREF="a3simple.php"> 3 Simple Queries</A>
        </DT>
        <DD><A HREF="a3simple.php#HowQueriesWork">How Queries Work</A></DD>
        <DD><A HREF="a3simple.php#Exercises">Exercises</A></DD>
        <DT>
          <P><A HREF="a4comqry.php"> 4 Compound Queries</A>
        </DT>
        <DD><A HREF="a4comqry.php#BuiltinPredicates"> Built-in Predicates</A></DD>
        <DD><A HREF="a4comqry.php#Exercises">Exercises</A></DD>
        <DT>
          <P><A HREF="a5rules.php"> 5 Rules</A>
        </DT>
        <DD><A HREF="a5rules.php#HowRulesWork">How Rules Work</A></DD>
        <DD><A HREF="a5rules.php#UsingRules">Using Rules</A></DD>
        <DD><A HREF="a5rules.php#Exercises">Exercises</A></DD>
        <DT>
          <P><A HREF="a6arith.php"> 6 Arithmetic</A>
        </DT>
        <DD><A HREF="a6arith.php#Exercises">Exercises</A></DD>
        <DT>
          <P><A HREF="a7manage.php"> 7 Managing Data</A>
        </DT>
        <DD><A HREF="a7manage.php#Exercises">Exercises</A></DD>
        <DT>
          <P><A HREF="a8recurs.php"> 8 Recursion</A>
        </DT>
        <DD><A HREF="a8recurs.php#HowRecursionWorks">How Recursion Works</A>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<BR>
        <DD><A HREF="a8recurs.php#Pragmatics">Pragmatics</A></DD>
        <DD><A HREF="a8recurs.php#Exercises">Exercises</A></DD>
      </DL>
</TD>

<TD VALIGN=TOP>
<DL>
<DT><A HREF="a9struct.php"> 9 Data Structures</A></DT>

<DD><A HREF="a9struct.php#Exercises">Exercises</A></DD>

<DT><P><A HREF="a10unif.php"> 10 Unification</A></DT>

<DD><A HREF="a10unif.php#Exercises">Exercises</A></DD>

<DT><P><A HREF="a11lists.php"> 11 Lists</A></DT>

<DD><A HREF="a11lists.php#UsingTheListUtilities">Using the List Utilities</A></DD>
<DD><A HREF="a11lists.php#Exercises">Exercises</A></DD>

<DT><P><A HREF="a12oper.php"> 12 Operators</A></DT>

<DD><A HREF="a12oper.php#Exercises">Exercises</A></DD>

<DT><P><A HREF="a13cut.php"> 13 Cut</A></DT>

<DD><A HREF="a13cut.php#UsingTheCut">Using the Cut</A></DD>
<DD><A HREF="a13cut.php#Exercises">Exercises</A></DD>

<DT><P><A HREF="a14cntrl.php"> 14 Control Structures</A></DT>

<DD><A HREF="a14cntrl.php#RecursiveControlLoop">Recursive Control Loop</A></DD>
<DD><A HREF="a14cntrl.php#TailRecursion">Tail Recursion</A></DD>
<DD><A HREF="a14cntrl.php#Exercises">Exercises</A></DD>

<DT><P><A HREF="a15nlang.php"> 15 Natural Language</A></DT>

<DD><A HREF="a15nlang.php#DifferenceLists">Difference Lists</A></DD>
<DD><A HREF="a15nlang.php#NaturalLanguageFrontEnd">Natural Language Front End</A></DD>
<DD><A HREF="a15nlang.php#DefiniteClauseGrammar">Definite Clause Grammar</A></DD>
<DD><A HREF="a15nlang.php#ReadingSentences">Reading Sentences</A></DD>
<DD><A HREF="a15nlang.php#Exercises">Exercises</A></DD>

<DT><P><A HREF="appendix.php"> Appendix</A></DT>

<DD><A HREF="appendix.php#NaniSearch">Nani Search</A></DD>
<DD><A HREF="appendix.php#Family">Family</A></DD>
<DD><A HREF="appendix.php#Custord">Custord</A></DD>
<DD><A HREF="appendix.php#Birds">Birds</A></DD>

<DT><P><A HREF="advidx.php">Index </A></DT>
</DL>
</TD>
</TR>
</TABLE>

<UL></UL>


<P>

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
