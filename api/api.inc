<?php
date_default_timezone_set("Asia/Taipei");
global $u;

require_once 'api/Mobile_Detect.inc';
$detect = new Mobile_Detect;
define('WEB', 'http://green.democracy.tw');

global $f;
global $key;
global $value;

//個人資料

$string = file_get_contents("http://v.democracy.tw/{$u}/site.json");
if($string) 	{ 
  $user = json_decode($string,true);
  $user = $user['nodes'][0]['node'];
}

//推薦
$string = file_get_contents("http://v.democracy.tw/{$u}/timeline.json/person");
$recommendation = json_decode($string,true);
$recommendation = $recommendation['nodes'];
$endorsment = $recommendation;
shuffle($recommendation);


//news
$string = file_get_contents("http://v.democracy.tw/{$u}/timeline.json/news");
$news = json_decode($string,true);
$news = $news['nodes'];
shuffle($news);

//function

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


function metavideo($url, $ssl) {

	$data = parse_url($url);
	$query = explode('&', $data['query']);
	
	//print_r($data);
	
	if($data['host'] == 'www.youtube.com' || $data['host'] == 'youtube.com' || $data['host'] == 'youtu.be') 
	{
		foreach($query as $q) 
	    { 
	    	//print_r($q);
    	    list($key, $value) = explode("=", $q); 
			if($key == 'v') { $video_id = $value; }
			if($ssl) { $url_new = 'https://www.youtube.com/v/'.$video_id; } else { $url_new = 'http://www.youtube.com/v/'.$video_id; }
			

	    } 	
    }
    
    
	return $url_new;
}


function filter_xss($string, $allowed_tags = array('a', 'em', 'strong', 'cite', 'code', 'ul', 'ol', 'li', 'dl', 'dt', 'dd')) {
  // Only operate on valid UTF-8 strings. This is necessary to prevent cross
  // site scripting issues on Internet Explorer 6.
  if (!drupal_validate_utf8($string)) {
    return '';
  }
  // Store the input format
  _filter_xss_split($allowed_tags, TRUE);
  // Remove NUL characters (ignored by some browsers)
  $string = str_replace(chr(0), '', $string);
  // Remove Netscape 4 JS entities
  $string = preg_replace('%&\s*\{[^}]*(\}\s*;?|$)%', '', $string);

  // Defuse all HTML entities
  $string = str_replace('&', '&amp;', $string);
  // Change back only well-formed entities in our whitelist
  // Decimal numeric entities
  $string = preg_replace('/&amp;#([0-9]+;)/', '&#\1', $string);
  // Hexadecimal numeric entities
  $string = preg_replace('/&amp;#[Xx]0*((?:[0-9A-Fa-f]{2})+;)/', '&#x\1', $string);
  // Named entities
  $string = preg_replace('/&amp;([A-Za-z][A-Za-z0-9]*;)/', '&\1', $string);

  return preg_replace_callback('%
    (
    <(?=[^a-zA-Z!/])  # a lone <
    |                 # or
    <!--.*?-->        # a comment
    |                 # or
    <[^>]*(>|$)       # a string that starts with a <, up until the > or the end of the string
    |                 # or
    >                 # just a >
    )%x', '_filter_xss_split', $string);
}


function drupal_validate_utf8($text) {
  if (strlen($text) == 0) {
    return TRUE;
  }
  // For performance reasons this logic is duplicated in check_plain().
  return (preg_match('/^./us', $text) == 1);
}