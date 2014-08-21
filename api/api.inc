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
$string = file_get_contents("http://v.democracy.tw/{$u}/site.json");
$user = json_decode($string,true);
$user = $user['nodes'][0]['node'];

//推薦
$string = file_get_contents("http://v.democracy.tw/{$u}/endorsment.json");
$recommendation = json_decode($string,true);
$recommendation = $recommendation['nodes'];
$endorsment = $recommendation;
shuffle($recommendation);


?>
