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


<h1>6</h1>
<hr />

<H2>Arithmetic</H2>

<P>Prolog must be able to handle arithmetic in order to be a useful general
purpose programming language. However, arithmetic does not fit nicely into
the logical scheme of things. </P>

<P>That is, the concept of evaluating an arithmetic expression is in contrast
to the straight pattern matching we have seen so far. For this reason,
Prolog provides the built-in predicate 'is' that evaluates arithmetic expressions.
Its syntax calls for the use of operators, which will be described in more
detail in chapter 12. </P>

<UL>
<PRE><FONT COLOR="#000080">X is &lt;arithmetic expression&gt;</FONT></PRE>
</UL>

<P>The variable X is set to the value of the arithmetic<!AMZI_INDEX=Arithmetic, affect on backtracking>
expression. On backtracking it is unassigned. </P>

<P>The arithmetic expression<!AMZI_INDEX= Arithmetic, expressions> looks
like an arithmetic expression in any other programming language. </P>

<P>Here is how to use Prolog as a calculator. </P>

<UL>
<PRE><FONT COLOR="#000080">?- X is 2 + 2.<!AMZI_INDEX= is/2
>
X = 4

?- X is 3 * 4 + 2.
X = 14</FONT></PRE>
</UL>

<P>Parentheses clarify precedence. </P>

<UL>
<PRE><FONT COLOR="#000080">?- X is 3 * (4 + 2).
X = 18

?- X is (8 / 4) / 2.
X = 1</FONT></PRE>
</UL>

<P>In addition to 'is,' Prolog provides a number of operators<!AMZI_INDEX= Operators; Arithmetic, operators>
that compare two numbers. These include 'greater than', 'less than', 'greater
or equal than', and 'less or equal than.' They behave more logically, and
succeed or fail according to whether the comparison is true or false. Notice
the order of the symbols in the greater or equal than and less than or
equal operators. They are specifically constructed not to look like an
arrow, so that you can use arrow symbols in your programs without confusion.
</P>

<UL>
<PRE><FONT COLOR="#000080">X &gt; Y
X &lt; Y
X &gt;= Y
X =&lt; Y</FONT></PRE>
</UL>

<P>Here are a few examples of their use. </P>

<UL>
<PRE><FONT COLOR="#000080">?- 4 &gt; 3.
yes

?- 4 &lt; 3.
no

?- X is 2 + 2, X &gt; 3.
X = 4

?- X is 2 + 2, 3 &gt;= X.
no

?- 3+4 &gt; 3*2.
yes</FONT></PRE>
</UL>

<P>They can be used in rules as well. Here are two example predicates.
One converts centigrade temperatures to Fahrenheit, the other checks if
a temperature is below freezing. </P>

<UL>
<PRE><FONT COLOR="#000080">c_to_f(C,F) :-
  F is C * 9 / 5 + 32.

freezing(F) :-
  F =&lt; 32.</FONT></PRE>
</UL>

<P>Here are some examples of their use. </P>

<UL>
<PRE><FONT COLOR="#000080">?- c_to_f(100,X).
X = 212
yes

?- freezing(15).
yes

?- freezing(45).
no</FONT></PRE>
</UL>

<H3><A NAME="Exercises"></A>Exercises</H3>

<H4>Customer Order Entry</H4>

<P>1- Write a predicate valid_order/3 that checks whether a customer order
is valid. The arguments should be customer, item, and quantity. The predicate
should succeed only if the customer is a valid customer with a good credit
rating, the item is in stock, and the quantity ordered is less than the
quantity in stock. </P>

<P>2- Write a reorder/1 predicate which checks inventory levels in the
inventory record against the reorder quantity in the item record. It should
write a message indicating whether or not it's time to reorder. </P>

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
