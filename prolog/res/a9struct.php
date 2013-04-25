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

<h1>9</h1>
<hr />

<H2>Data Structures</H2>

<P>So far we have worked with facts, queries, and rules that use simple
data structures. The arguments to our predicates have all been atoms or
integers, the basic building blocks of Prolog. Examples of atoms we've
used are </P>

<UL>
<PRE><FONT COLOR="#000080">office, apple, flashlight, nani</FONT></PRE>
</UL>

<P>These primitive data types can be combined to form arbitrarily complex
data types called structures<!AMZI_INDEX= Structures>. A structure is composed
of a functor and a fixed number of arguments. Its form is just like that
of the goals and facts we've seen already (for good reason, we'll discover).
</P>

<UL>
<PRE><FONT COLOR="#000080">functor(arg1,arg2,...)</FONT></PRE>
</UL>

<P>Each of the structure's arguments can be either a primitive data type
or another structure. For example, the things in the game are currently
represented using atoms, such as 'desk' or 'apple,' but we can use structures
to create a richer representation of these things. The following structures
describe the object and its color, size, and weight. </P>

<UL>
<PRE><FONT COLOR="#000080">object(candle, red, small, 1).<!AMZI_INDEX=  object/4>
object(apple, red, small, 1).
object(apple, green, small, 1).
object(table, blue, big, 50).</FONT></PRE>
</UL>

<P>These structures could be used directly in the second argument of location/2,
but for experimentation we will instead create a new predicate, location_s/2.
Note that even though the structures describing the objects in the game
are complex, they still take up only one argument in location_s/2. </P>

<UL>
<PRE><FONT COLOR="#000080">location_s(object(candle, red, small, 1), kitchen).<!AMZI_INDEX= location_s/2>
location_s(object(apple, red, small, 1), kitchen).
location_s(object(apple, green, small, 1), kitchen).
location_s(object(table, blue, big, 50), kitchen).</FONT></PRE>
</UL>

<P>Prolog variables<!AMZI_INDEX= Unification, structures> are typeless,
and can be bound as easily to structures as to atoms. In fact, an atom
is just a simple structure with a functor and no arguments. So we can ask
</P>

<UL>
<PRE><FONT COLOR="#000080">?- location_s(X, kitchen).
X = object(candle, red, small, 1) ;
X = object(apple, red, small, 1) ;
X = object(apple, green, small, 1) ;
X = object(table, blue, big, 50) ;
no</FONT></PRE>
</UL>

<P>We can also pick apart the structure with variables. We can now find
all the red things in the kitchen. </P>

<UL>
<PRE><FONT COLOR="#000080">?- location_s(object(X, red, S, W), kitchen).
X = candle
S = small
W = 1 ;

X = apple
S = small
W = 1 ;
no</FONT></PRE>
</UL>

<P>If we didn't care about the size and weight we could replace the size,
S, and weight, W, variables with the anonymous variable (_). </P>

<UL>
<PRE><FONT COLOR="#000080">?- location_s(object(X, red, _, _), kitchen).
X = candle ;
X = apple ;
no</FONT></PRE>
</UL>

<P>We can use these structures to add more realism to the game. For example,
we can modify our can_take/1 predicate, developed in chapter 7, so that
we can only take small objects. </P>

<UL>
<PRE><FONT COLOR="#000080">can_take_s(Thing) :-
  here(Room),
  location_s(object(Thing, _, small,_), Room).</FONT></PRE>
</UL>

<P>We can also change the error messages to reflect the two reasons why
a thing cannot be taken. To ensure that backtracking does not cause both
errors to be displayed, we will construct each clause so its message is
displayed only when its unique conditions are met. To do this, the built-in
predicate not/1 is used. Its argument is a goal, and it succeeds if its
argument fails, and fails if its argument succeeds. For example </P>

<UL>
<PRE><FONT COLOR="#000080">?- not( room(office) ).
no

?- not( location(cabbage, 'living room') )
yes</FONT></PRE>
</UL>

<P>Note that semantically, not in Prolog means the goal cannot be successfully
solved with current logicbase of facts and rules. Here is how we use not/1<!AMZI_INDEX= not/1>
in our new version, can_take_s/1. </P>

<UL>
<PRE><FONT COLOR="#000080">can_take_s(Thing) :-&lt;<!AMZI_INDEX=  can_take_s/1> 
  here(Room),
  location_s(object(Thing, _, small, _), Room).
can_take_s(Thing) :-
  here(Room),
  location_s(object(Thing, _, big, _), Room),
  write('The '), write(Thing), 
  write(' is too big to carry.'), nl,
  fail.
can_take_s(Thing) :-
  here(Room),
  not (location_s(object(Thing, _, _, _), Room)),
  write('There is no '), write(Thing), write(' here.'), nl,
  fail.</FONT></PRE>
</UL>

<P>We can now try it, assuming we are in the kitchen. </P>

<UL>
<PRE><FONT COLOR="#000080">?- can_take_s(candle).
yes

?- can_take_s(table).
The table is too big to carry.
no

?- can_take_s(desk).
There is no desk here.
no</FONT></PRE>
</UL>

<P>The list_things/1 predicate can be modified to give a description of
the things in a room. </P>

<UL>
<PRE><FONT COLOR="#000080">list_things_s(Place) :-<!AMZI_INDEX=  list_things_s/1>  
  location_s(object(Thing, Color, Size, Weight),Place),
  write('A '),write(Size),tab(1),
  write(Color),tab(1),
  write(Thing), write(', weighing '),
  write(Weight), write(' pounds'), nl,
  fail.
list_things_s(_).</FONT></PRE>
</UL>

<P>Requesting it now gives a more detailed list. </P>

<UL>
<PRE><FONT COLOR="#000080">?- list_things_s(kitchen).
A small red candle, weighing 1 pounds
A small red apple, weighing 1 pounds
A small green apple, weighing 1 pounds
A big blue table, weighing 50 pounds
yes</FONT></PRE>
</UL>

<P>If you are bothered by the grammatically incorrect '1 pounds', you can
fix it by adding another rule to write the weight, which would replace
the direct 'writes' now used. </P>

<UL>
<PRE><FONT COLOR="#000080">write_weight(1) :-
  write('1 pound').
write_weight(W) :-
  W &gt; 1,
  write(W), write(' pounds').</FONT></PRE>
</UL>

<P>Testing it shows it works as desired. </P>

<UL>
<PRE><FONT COLOR="#000080">?- write_weight(4).
4 pounds
yes

?- write_weight(1).
1 pound
yes\</FONT></PRE>
</UL>

<P>Notice that we did not need to put a test, such as 'W = 1,' in the first
clause. By putting the 1 directly in the argument at the head of the clause
we ensure that that clause will only be fired when the query goal is write_weight(1).
All other queries will go to the second clause because the goal pattern
will fail to unify with the head of the first clause. </P>

<P>It is important, however, to put the test 'W &gt; 1' in the second rule.
Otherwise both rules would work for a weight of 1. The first time the predicate
was called would not be a problem, but on backtracking we would get two
answers if we had not included the test. </P>

<P>Structures<!AMZI_INDEX= Structures, complex> can be arbitrarily complex,
so if we wanted to get fancy about things in the game we could keep their
dimensions (length, width, height) instead of their size as part of their
description. </P>

<UL>
<PRE><FONT COLOR="#000080">object(desk, brown, dimension(6,3,3), 90).</FONT><!AMZI_INDEX= object/4></PRE>
</UL>

<P>We can also use embedded structures for clarity. </P>

<UL>
<PRE><FONT COLOR="#000080">object(desk, color(brown), size(large), weight(90))</FONT></PRE>
</UL>

<P>A query using these structures is more readable. </P>

<UL>
<PRE><FONT COLOR="#000080">location_s(object(X, _, size(large), _), office).</FONT></PRE>
</UL>

<P>Notice that the position of the arguments is important. The place-holding
anonymous variables<!AMZI_INDEX=  Anonymous variables> are essential for
getting the correct results. </P>

<H3><A NAME="Exercises"></A>Exercises</H3>

<H4>Adventure Game</H4>

<P>1- Incorporate the new location into the game. Note that due to data
and procedure abstraction, we need only change the low level predicates
that deal directly with location. The higher level predicates, such as
look/0 and take/1 are unaffected by the change. </P>

<H4>Customer Order Entry</H4>

<P>2- Use structures to enhance the customer order entry application. For
example, include a structure for each customers address. </P>


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
