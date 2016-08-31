<?php

mike();
echo "<br/>";
/*echo mike_age();
echo "<br/>";

echo mike_name();
echo "<br/>";

var_dump(mike_love());
var_dump(mike_talk('hello'));

mike_say("hello", 23);

echo mike_default("mikewang");
*/
echo  "<br/>";
$obj = new myclass();
var_dump($obj);
$obj->public_method();
$obj->static_method();
echo "<br/><p>end</p>";

var_dump(myclass::VERSION);
var_dump($obj->connected);
