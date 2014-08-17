<?php

require_once 'api/Mobile_Detect.php';
$detect = new Mobile_Detect;


function SL($str,$len,$name=null){

if(!eregi("[^\x80-\xff]","$str")){
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

?>