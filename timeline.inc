<?php
require_once 'api/api.inc';

//分頁

//newsfeeds
$string = file_get_contents("http://v.democracy.tw/{$u}/news.json");
$newsfeeds = json_decode($string,true);
$newsfeeds = $newsfeeds['nodes'];

//政見

$string = file_get_contents('http://v.democracy.tw/test/event.json');
$events = json_decode($string, true);
$events = $events['nodes'];

//活動

$string = file_get_contents('http://v.democracy.tw/test/issue.json');
$issues = json_decode($string, true);
$issues = $issues['nodes'];

//相簿

$string = file_get_contents('http://v.democracy.tw/test/galleries.json');
$gallery = json_decode($string, true);
$gallery = $gallery['nodes'];

foreach($gallery as $key => $v) {
	$gallery[$key]['node']['date'] = date("Y-m-d" ,strtotime($v['node']['post date']));
}
	

//推薦
//$endorsment already get from api.icnc


//combian_all arrays
$all_feeds = array_merge($newsfeeds, $events, $issues, $gallery, $endorsment);


//sorting
$i = 0;
foreach($all_feeds as $key => $v) {
	$v['node']['sort_id'] = 'sort-'.$i;
	$all_feeds_new[] = $v;
	$i ++;
}

$rows = aasort($all_feeds_new,"date");
//print_r(json_encode($all_feeds_new, true));
//print_r(json_encode($rows, true));



//處理 json;
	
			$cats = array(
			    "newsfeed" => array("blog_post", "選舉動態",200),
			    "slider" => array("slider", "選舉動態", 200),
			    "video" => array("iframe", "選舉動態", 300),
		    	"newsclip" => array("news", "相關新聞",200),

		    	"FAQ" => array("blog_post", "政見", 200),
		    	"Person" => array("blog_post", "各界推薦", 200),
		    	"Event" => array("blog_post", "活動行程", 200),
		    	"gallery" => array("blog_post", "相簿", 300),
			);


function aasort ($array, $key) {

    $sorter=array();
    $ret=array();

    foreach ($array as $ii => $va) {
        $sorter[$va['node']['sort_id']] = $va['node'][$key]; //depends on format of array
    }

    arsort($sorter); //DESC by vaule with key
    	
    foreach ($sorter as $ii => $va) {
    	if($va) {
    		foreach ($array as $k => $value) {
    			if($value['node']['sort_id'] == $ii) {
			        $ret[]=$value;
    			}
    		}	        
	    }
    }
        
    $array=$ret;    
    return $array;
}

?>