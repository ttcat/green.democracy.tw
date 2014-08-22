<?php
date_default_timezone_set("Asia/Taipei");
global $u;

require_once 'api/Mobile_Detect.inc';
$detect = new Mobile_Detect;

function SL($str,$len,$name=null){

if(!preg_match("[/^\x80-\xff]","$str")) {
	$len = $len;
}else{
	$len = $len +2;
}

	mb_internal_encoding("UTF-8");
	$str = str_replace('<br>','',$str);
	if( mb_strlen($str) > $len){ $dot='...';} else { $dot=''; }
	
	if($name == 1) { $dot = ''; }

	return mb_substr($str,0,$len).$dot;

}

define('WEB', 'http://green.democracy.tw');

global $f;
global $key;
global $value;

//個人資料
if(file_exists('http://v.democracy.tw/{$u}/site.json')) {

	$string = file_get_contents("http://v.democracy.tw/{$u}/site.json");
	$user = json_decode($string,true);
	$user = $user['nodes'][0]['node'];

	//推薦
	$string = file_get_contents("http://v.democracy.tw/{$u}/endorsment.json");
	$recommendation = json_decode($string,true);
	$recommendation = $recommendation['nodes'];
	$endorsment = $recommendation;
	shuffle($recommendation);
	
}else{
?>
<html>
<head>
<meta http-equiv="content-type" content="text/html;charset=utf-8">
<title>Error 404 Not Found api</title>
<style>
<!--
  body {font-family: arial,sans-serif}
  img { border:none; }
//-->
</style>
</head>
<body>
<div align="center">
<h1>404 Not Found</h1>
<hr>
Nginx
</div>
</body>
</html>
<?
 exit();
}
?>
