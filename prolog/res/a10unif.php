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

<h1>10</h1>
<hr />

<H2>Unification</H2>

<P>One of Prolog's most powerful features is its built-in pattern-matching
algorithm, unification<!AMZI_INDEX= Unification>. For all of the examples
we have seen so far, unification has been relatively simple. We will now
examine unification more closely. </P>

<P>The full definition of unification is similar to the one given in chapter
3, with the addition of a recursive definition to handle data structures.
This following table summarizes the unification process. </P>

<TABLE BORDER=1 CELLPADDING=3 >
<TR>
<TD WIDTH=113>variable<BR>
&amp;<BR>
any term </TD>

<TD WIDTH=252>The variable will unify with and is bound to any term, including
another variable. </TD>
</TR>

<TR>
<TD WIDTH=113>primitive<BR>
&amp;<BR>
primitive </TD>

<TD WIDTH=252>Two primitive terms (atoms or integers) unify only if they
are identical. </TD>
</TR>

<TR>
<TD WIDTH=113>structure<BR>
&amp;<BR>
structure </TD>

<TD WIDTH=252>Two structures unify if they have the same functor and arity
and if each pair of corresponding arguments unify. </TD>
</TR>
</TABLE>

<P>In order to experiment with unification we will introduce the built-in
predicate =/2<!AMZI_INDEX=  =/2>, which succeeds if its two arguments unify
and fails if they do not. It can be written in operator syntax as follows.
</P>

<UL>
<PRE><FONT COLOR="#000080">arg1 = arg2</FONT></PRE>
</UL>

<P>which is equivalent to </P>

<UL>
<PRE><FONT COLOR="#000080">=(arg1, arg2)</FONT></PRE>
</UL>

<P>WARNING: The equal sign (=) does not cause assignment as in most programming
languages, nor does it cause arithmetic evaluation. It causes Prolog unification.
(Despite this warning, if you are like most mortal programmers, you will
be tripped up by this difference more than once.) </P>

<P>Unification between two sides of an equal sign (=) is exactly the same
as the unification that occurs when Prolog tries to match goals with the
heads of clauses. On backtracking, the variable bindings are undone, just
as they are when Prolog backtracks through clauses<!AMZI_INDEX=  =/2, affect on backtracking>.
</P>

<P>The simplest form of unification occurs between two structures<!AMZI_INDEX= Structures, unification; Unification, structures>
with no variables. In this case, either they are identical and unification
succeeds, or they are not, and unification fails. </P>

<UL>
<PRE><FONT COLOR="#000080">?- a = a.
yes

?- a = b.
no

?- location(apple, kitchen) = 
location(apple, kitchen).
yes

?- location(apple, kitchen) = 
location(pear, kitchen).
no

?- a(b,c(d,e(f,g))) = a(b,c(d,e(f,g))).
yes

?- a(b,c(d,e(f,g))) = a(b,c(d,e(g,f))).
no</FONT></PRE>
</UL>

<P>Another simple form of unification occurs between a variable and a primitive.
The variable takes on a value that causes unification to succeed. </P>

<UL>
<PRE><FONT COLOR="#000080">?- X = a.
X = a 

?- 4 = Y.
Y = 4 

?- location(apple, kitchen) = location(apple, X).
X = kitchen </FONT></PRE>
</UL>

<P>In other cases multiple variables are simultaneously bound to values.
</P>

<UL>
<PRE><FONT COLOR="#000080">?- location(X,Y) = location(apple, kitchen).
X = apple
Y = kitchen 

?- location(apple, X) = location(Y, kitchen).
X = kitchen
Y = apple </FONT></PRE>
</UL>

<P>Variables can also unify with each other. Each instance of a variable
has a unique internal Prolog value. When two variables are unified to each
other, Prolog notes that they must have the same value. In the following
example, it is assumed Prolog uses '_nn,' where 'n' is a digit, to represent
unbound variables<!AMZI_INDEX=  Variables, unbound>. </P>

<UL>
<PRE><FONT COLOR="#000080">?- X = Y.
X = _01
Y = _01 

?- location(X, kitchen) = location(Y, kitchen).
X = _01
Y = _01 </FONT></PRE>
</UL>

<P>Prolog remembers the fact that the variables are bound together and
will reflect this if either is later bound. </P>

<UL>
<PRE><FONT COLOR="#000080">?- X = Y, Y = hello.
X = hello
Y = hello 

?- X = Y, a(Z) = a(Y), X = hello.
X = hello
Y = hello
Z = hello </FONT></PRE>
</UL>

<P>The last example is critical to a good understanding of Prolog and illustrates
a major difference between unification with Prolog variables and assignment
with variables found in most other languages. Note carefully the behavior
of the following queries. </P>

<UL>
<PRE><FONT COLOR="#000080">?- X = Y, Y = 3, write(X).
3
X = 3
Y = 3 

?- X = Y, tastes_yucky(X), write(Y).
broccoli
X = broccoli
Y = broccoli </FONT></PRE>
</UL>

<P>When two structures with variables are unified with each other, the
variables take on values that make the two structures identical. Note that
a structure bound to a variable can itself contain variables. </P>

<UL>
<PRE><FONT COLOR="#000080">?- X = a(b,c).<!AMZI_INDEX=  =/2
>
X = a(b,c) 

?- a(b,X) = a(b,c(d,e)).
X = c(d,e) 

?- a(b,X) = a(b,c(Y,e)).
X = c(_01,e)
Y = _01 </FONT></PRE>
</UL>

<P>Even in these more complex examples, the relationships between variables
are remembered and updated as new variable bindings occur. </P>

<UL>
<PRE><FONT COLOR="#000080">?- a(b,X) = a(b,c(Y,e)), Y = hello.
X = c(hello, e)
Y = hello

?- food(X,Y) = Z, write(Z), nl, tastes_yucky(X), edible(Y), write(Z).

food(_01,_02)
food(broccoli, apple)
X = broccoli
Y = apple
Z = food(broccoli, apple) </FONT></PRE>
</UL>

<P>If a new value assigned to a variable in later goals conflicts with
the pattern set earlier, the goal fails. </P>

<UL>
<PRE><FONT COLOR="#000080">?- a(b,X) = a(b,c(Y,e)), X = hello.
no</FONT></PRE>
</UL>

<P>The second goal failed since there is no value of Y that will allow
hello to unify with c(Y,e). The following will succeed. </P>

<UL>
<PRE><FONT COLOR="#000080">?- a(b,X) = a(b,c(Y,e)), X = c(hello, e).
X = c(hello, e)
Y = hello </FONT></PRE>
</UL>

<P>If there is no possible value the variable can take on, then unification
fails. </P>

<UL>
<PRE><FONT COLOR="#000080">?- a(X) = a(b,c).
no

?- a(b,c,d) = a(X,X,d).
no</FONT></PRE>
</UL>

<P>The last example failed because the pattern asks that the first two
arguments be the same, and they aren't. </P>

<UL>
<PRE><FONT COLOR="#000080">?- a(c,X,X) = a(Y,Y,b).
no</FONT></PRE>
</UL>

<P>Did you understand why this example fails? Matching the first argument
binds Y to c. The second argument causes X and Y to have the same value,
in this case c. The third argument asks that X bind to b, but it is already
bound to c. No value of X and Y will allow these two structures to unify.
</P>

<P>The anonymous variable<!AMZI_INDEX=  Anonymous variables> (_) is a wild
variable, and does not bind to values. Multiple occurrences of it do not
imply equal values. </P>

<UL>
<PRE><FONT COLOR="#000080">?- a(c,X,X) = a(_,_,b).
X = b </FONT></PRE>
</UL>

<P>Unification occurs explicitly when the equal (=) built-in predicate
is used, and implicitly when Prolog searches for the head of a clause that
matches a goal pattern. </P>

<H3><A NAME="Exercises"></A>Exercises</H3>

<H4>Nonsense Prolog</H4>

<P>Predict the results of these unification queries. </P>

<UL>
<PRE><FONT COLOR="#000080">?- a(b,c) = a(X,Y).

?- a(X,c(d,X)) = a(2,c(d,Y)).

?- a(X,Y) = a(b(c,Y),Z).

?- tree(left, root, Right) = tree(left, root, tree(a, b, tree(c, d, e))).</FONT></PRE>
</UL>


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
