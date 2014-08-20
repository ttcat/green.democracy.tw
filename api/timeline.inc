<?php
require_once 'api.inc';

//分頁
$perpage = 3;
$pageq = explode('?' , $timeline_page_query);

$start_feed = ( (int) $pageq[0] ) * 3;
$end_feed = $start_feed + 2;


/*
//newsfeeds
$string = file_get_contents("http://v.democracy.tw/{$u}/news.json");
$newsfeeds = json_decode($string,true);
$newsfeeds = $newsfeeds['nodes'];

//活動
//$string = file_get_contents("http://v.democracy.tw/{$u}/event.json");
//$events = json_decode($string, true);
//$events = $events['nodes'];

//政見
$string = file_get_contents("http://v.democracy.tw/{$u}/issue.json");
$issues = json_decode($string, true);
$issues = $issues['nodes'];

//相簿	
$string = file_get_contents("http://v.democracy.tw/{$u}/galleries.json");
$gallery = json_decode($string, true);
$gallery = $gallery['nodes'];

foreach($gallery as $key => $v) {
	$gallery[$key]['node']['date'] = date("Y-m-d" ,strtotime($v['node']['post date']));
}

//推薦
//$endorsment already get from api.icnc



//combian_all arrays
$all_feeds = array_merge($newsfeeds, $issues, $gallery, $endorsment);
*/

$string = file_get_contents("http://v.democracy.tw/{$u}/timeline.json");
$all_feeds = json_decode($string,true);
$all_feeds = $newsfeeds['nodes'];


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
			    "newsfeed" => array("blog_post", "選舉動態",200, ''),
			    "slider" => array("slider", "選舉動態", 200, ''),
			    "video" => array("iframe", "選舉動態", 300, ''),
		    	"newsclip" => array("news", "相關新聞",200, ''),

		    	"FAQ" => array("blog_post", "政見", 200, 'issues/'),
		    	"Person" => array("blog_post", "各界推薦", 200, 'endorsements/'),
		    	"Event" => array("blog_post", "活動行程", 200, 'event/'),
		    	"gallery" => array("gallery", "相簿", 300, ''),
			);


		$jj = 0;
		$json = array();
		
		foreach ($rows as $k => $feed) { 

			$feed = $feed['node'];
			
			if($feed['type'] == "") { $feed['type'] = 'gallery'; }  //測試

			if($feed['type'] == "News") { 
				if( ! $feed['category']) $feed['category'] = 'newsfeed';

				if($feed['category'] == 'slider') { 
					$media = explode("|", $feed['photo']);	
				}
				$json_this_feed['type'] = $cats[ $feed['category'] ][0];
				$json_this_feed['title'] = $cats[$feed['category']][1];
				$json_this_feed['height'] = $cats[$feed['category']][2];
				$linkpage = $cats[$feed['category']][3];	
				
			}else{
				$json_this_feed['type'] = $cats[ $feed['type'] ][0];
				$json_this_feed['title'] = $cats[$feed['type']][1];
				$json_this_feed['height'] = $cats[$feed['type']][2];
				$linkpage = $cats[$feed['type']][3];	
			}

			
			if($feed['media']) { 
				$media = explode("|", $feed['media']);	
				$json_this_feed['images'] = $media;
			}
				
			if($feed['photo']) { 
			    $json_this_feed['image'] = $feed['photo'];
			}
			
			
			$json_this_feed['date'] = date('Y-m-d' , strtotime($feed['date']));
			$json_this_feed['dateFormat'] = 'YYYY-MM-DD';
			$json_this_feed['speed'] = 5000;
			$json_this_feed['nid'] = $feed['nid'];


			if($feed['sticky'] == "Yes") { $json_this_feed['star'] = true; }	//置頂

			//<span class="icon-"></span> 標題前面加上 icon

			if($feed['link']) {					
				$parse_result = '';
				$parse_result = parse_url($feed['link']);
				if($parse_result['host'] != $_SERVER['HTTP_HOST'] ) { $target = 'target="blank"'; } else { $target = ''; }
				$feed['title'] = '<a href="'.$feed['link'].'" '.$target.'>' . $feed['title'] . '</a>';
				$json_this_feed['readmore'] = $feed['link'];
			}

			if($feed['category'] == 'video') { 
				$json_this_feed['url'] = $feed['videolink'];
			}			
			

			$feed['content'] = SL(str_replace("\n","",$feed['content']),250);

			$event_time = '';
			//event 加上按鈕
			if($feed['type'] == 'Event') { 
					$feed['content'] = '<p>' . $feed['content'] . '</p><p></p><a href="'. $feed['link'] .'" class="btn small-btn"><em class="fa fa-chevron-sign-right"></em>我要參加！</a><br>'; 
					$event_time = '<h6>' . $feed['eventtime']  . ' <br> ' . $feed['location'] .'</h6>';
				}

            $json_this_feed['content'] = '<h3>' . $feed['title'] . '</h3><p>' . $event_time . $feed['content']  . '<div id="timeline_fb_' . $feed['nid'] .'" class="addthis_sharing_toolbox" data-url="http://green.democracy.tw/' . $u . '/' .$linkpage. 'nid/' . $feed['nid'] . '"></div></p>';
            if($target) { $json_this_feed['target'] = 'target="blank"'; }else{ $json_this_feed['target'] = ''; } 


			
			//分頁控制在此
			if($jj >= $start_feed && $jj <= $end_feed) {
				$json[0] = (array) $json_this_feed;
			}		
			
			$jj ++;
		} //end foreach	

//	$json['total'] = count($rows);
//	$json['thispage'] = $start_feed;
	
	$json_str = json_encode($json);
//	$json_str = substr($json_str, 0, -1);
	print_r($json_str);			
//	echo '[' . $json_str . ']';

///

function aasort ($array, $key) {

    $sorter=array();
    $ret=array();

    foreach ($array as $ii => $va) {

    	if($va['node']['sticky'] = "Yes" ) { 
        	$sorter[$va['node']['sort_id']] = '9' . $va['node'][$key]; //depends on format of array
        }else{
        	$sorter[$va['node']['sort_id']] = $va['node'][$key]; //depends on format of array        
        }
        
    }

    arsort($sorter); //DESC by vaule with key
    	
    foreach ($sorter as $ii => $va) {
    	if($va) {
    		foreach ($array as $k => $value) {
    			if($value['node']['sort_id'] == $ii) {
			        $ret[] = $value;
    			}
    		}	        
	    }
    }
        
    $array=$ret;    
    return $array;
}

?>